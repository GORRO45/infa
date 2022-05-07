#include <iostream>
#include <thread>
#include<stdio.h>
#include<math.h>

double circle(double, double);

double circle(double x, double radius)
{
double y=radius*radius-x*x;
return y;
}
int main()
{
    const size_t N = 500000, num_threads = std::thread::hardware_concurrency();
    
    std::thread t[num_threads];
    
  
    auto func = [num_threads](size_t start, size_t end, double &result) {
        auto sum = 0.0;
        auto j = 0.0;
        for (auto i = start; i < end; i++)
           
        j=0;
            double x,y;
            while (j<50000)
        {
        x = (random() % (10000*100))/100;
        y = (random() % (10000*100))/100;
            if (y*y<=circle(x,(10000)))
            {
            sum= sum+1;
            }
        j++;
        }

        
        result = sum;
    };
    
    auto sum = 0.0;
    size_t i;
    
    for (i = 0; i < num_threads - 1; i++)
        t[i] = std::thread(func, i * num_threads, (i + 1) * num_threads, std::ref(sum));
    
    if (i * num_threads < N)
        t[i] = std::thread(func, i * num_threads, N, std::ref(sum));
    for (auto &thread : t)
        thread.join();
    

    std::cout << (4*sum / 50000) << std::endl;
}
