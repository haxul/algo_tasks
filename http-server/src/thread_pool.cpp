#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#include "http_handler.cpp"

using namespace std;

class ThreadPool {
   private:
    vector<thread> threads_;

    queue<HttpHandler*> tasks_;

    size_t num_threads_;

    mutex queue_mutex_;

    condition_variable cv_;

    bool stop_ = false;

   public:
    ThreadPool(size_t num_threads) : num_threads_(num_threads) {
        for (size_t i = 0; i < num_threads; ++i) {
            threads_.emplace_back([this] {
                while (true) {
                    HttpHandler* handler;
                    {
                        unique_lock<mutex> lock(queue_mutex_);

                        cv_.wait(lock,
                                 [this] { return !tasks_.empty() || stop_; });

                        if (stop_ && tasks_.empty()) {
                            return;
                        }

                        handler = tasks_.front();
                        tasks_.pop();
                    }

                    handler->run();
                    delete handler;
                }
            });
        }
    }

    ~ThreadPool() {
        {
            unique_lock<mutex> lock(queue_mutex_);
            stop_ = true;
        }

        cv_.notify_all();

        for (auto& thread : threads_) {
            thread.join();
        }
    }

    void Enqueue(HttpHandler* handler) {
        {
            unique_lock<std::mutex> lock(queue_mutex_);
            tasks_.emplace(handler);
        }
        cv_.notify_one();
    }
};
