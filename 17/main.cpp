#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
using namespace std;

mutex mtx;

void background_job(string value, int end) {
  lock_guard<mutex> guard(mtx);
  for (size_t i = 0; i < end; i++) {
    cout << value;
  }
  cout << endl;
}

int main() {

  unsigned int n_threads = thread::hardware_concurrency();
  cout << "N Threads (supported): " << n_threads << endl;

  int n = 100;

  // static thread definition (n=4)
  thread t1(background_job, "BACKGROUND", n);
  thread t2(background_job, "1", n);
  thread t3(background_job, "2", n);
  thread t4(background_job, "3", n);
  t1.join();
  t2.join();
  t3.join();
  t4.join();

  const auto start1{chrono::steady_clock::now()};

  // dynamic thread definition (n=n_threads)
  vector<thread> threads;
  for (int i = 0; i < n_threads; i++) {
    threads.push_back(thread(background_job, to_string(i), n));
  }

  for (int i = 0; i < n_threads; i++) {
    threads[i].join();
  }

  const auto end1{chrono::steady_clock::now()};
  const auto elapsed1 =
      chrono::duration_cast<chrono::microseconds>(end1 - start1).count();

  cout << "Time elapsed: " << elapsed1 << endl;

  return 0;
}
