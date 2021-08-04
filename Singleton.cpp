/*
 * @Description: 单例模式/懒汉式
 * @Version: 
 * @Autor: Leonard Niu
 * @Date: 2021-08-03 20:43:19
 * @LastEditors: Leonard Niu
 * @LastEditTime: 2021-08-04 19:58:56
 */

#include <iostream>

#include <thread>
#include <mutex>

#include <atomic>


class Box
{
public:
    
    class Gabor
    {
    public:
        ~Gabor();
    };
    static Box* GetInstance(double width, double height);
    static void CountInstance();

private:
    double mWidth;
    double mHeight;    

    static unsigned int mInstanceNum;
    static Gabor mGabor;
    //static Box* mSingleton;
    static std::atomic<Box*> mSingleton;
    static std::mutex mMutex;

    // Box() = default;
    Box(double width, double height);
};

// 采用atomic operation保证内存序
unsigned int Box::mInstanceNum(0);
Box::Gabor Box::mGabor;
std::atomic<Box*> Box::mSingleton;
std::mutex Box::mMutex;

Box::Gabor::~Gabor()
{
    if (mSingleton != nullptr)
    {
        delete mSingleton;
    }
}

Box::Box(double width, double height):
    mWidth(width), mHeight(height){}


/*
* std::atomic_thread_fence(std::memory_order_acquire); 
* std::atomic_thread_fence(std::memory_order_release);
* 这两句话可以保证他们之间的语句不会发生乱序执行。
*/
Box* Box::GetInstance(double width, double height)
{
	Box* temp = mSingleton.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);

    if (temp == nullptr)
    {
        std::lock_guard<std::mutex> lGuard(mMutex);
        temp = mSingleton.load(std::memory_order_relaxed);
        if (temp == nullptr)
        {
            temp = new Box(width, height);
            std::atomic_thread_fence(std::memory_order_release);
            mSingleton.store(temp, std::memory_order_relaxed);
            ++mInstanceNum;
        }
    }
    return mSingleton;
}

void Box::CountInstance()
{
    std::cout << "当前实例个数为: " << mInstanceNum << std::endl;
}

int main()
{
    Box* box1 = Box::GetInstance(10.0, 10.0);
    Box::CountInstance();
    Box* box2 = Box::GetInstance(10.0, 10.0);
    Box::CountInstance();
    return 0;
}