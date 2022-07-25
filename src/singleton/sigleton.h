#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>
#include <mutex>

template <typename T>
class singleton {
public:
	static T *get_instance() {
		if (nullptr == instance_) {
			std::call_once(once_f_, [&]() { singleton::instance_.reset(new T()); });
		}
		return instance_.get();
	}

private:
	singleton();
	singleton(const singleton &rhs) = delete;
	singleton &operator=(const singleton &rhs) = delete;

private:
	static std::unique_ptr<T> instance_;
	static std::once_flag once_f_;
};

template <typename T>
std::unique_ptr<T> singleton<T>::instance_ = nullptr;

template <typename T>
std::once_flag singleton<T>::once_f_;

#endif // !SINGLETON_H