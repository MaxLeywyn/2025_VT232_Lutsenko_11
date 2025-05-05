#ifndef SMARTPTR_H
#define SMARTPTR_H

template <typename T>
class smart_ptr {
    T* obj;
public:
    smart_ptr(T* obj = nullptr) : obj(obj) {}
    ~smart_ptr() {
        delete obj;
    }

    // Запрещаем копирование
    smart_ptr(const smart_ptr&) = delete;
    smart_ptr& operator=(const smart_ptr&) = delete;

    // Разрешаем перемещение
    smart_ptr(smart_ptr&& other): obj(other.obj) {
        other.obj = nullptr;
    }

    smart_ptr& operator=(smart_ptr&& other) {
        if (this != &other) {
            delete obj;
            obj = other.obj;
            other.obj = nullptr;
        }
        return *this;
    }

    T* operator->() const {
        return obj;
    }

    T& operator*() const {
        return *obj;
    }

    T* get() const {
        return obj;
    }

    void reset(T* ptr = nullptr) {
        delete obj;
        obj = ptr;
    }
};

#endif // SMARTPTR_H
