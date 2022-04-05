#include <memory_resource>
#include <vector>
#include <string>
#include <array>
#include <iostream>

int main()
{
    std::array<int, 30> aArray {0} ;
    // スレッドセーフなメモリプールを使用する
    std::pmr::monotonic_buffer_resource mem_res(aArray.data(), aArray.size(), std::pmr::null_memory_resource());

    try {
        std::pmr::vector<int> aVector(&mem_res);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);
        aVector.push_back(10);

        for (auto& aItem : aVector) {
            std::cout << aItem << std::endl;
        }
    }
    catch (std::exception iEx) {
        std::cout << iEx.what() << std::endl;
    }
}

