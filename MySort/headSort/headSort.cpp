#include<iostream>
#include<vector>
using namespace std;
//author: Zhao Jiaxing, 直接看代码即可，注释包含解释
class Solution
{
    public:
    // 递归方式构建小根堆(len是arr的长度，index是第一个非叶子节点的下标)
    void adjust(vector<int>& arr, int len, int index)
    {
        int left = 2 * index + 1; // index的左子节点
        int right = 2 * index + 2;// index的右子节点

        int minIdx = index;
        if (left < len && arr[left] < arr[minIdx])       minIdx = left;
        if (right < len && arr[right] < arr[minIdx])     minIdx = right;

        if (minIdx != index)
        {
            swap(arr[minIdx], arr[index]);
            adjust(arr, len, minIdx);
        }

    }

    // 堆排序
    void heapSort(vector<int>& arr, int size)
    {
        // 构建根堆（从最后一个非叶子节点向上）
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            adjust(arr, size, i);
        }

        // 调整根堆
        for (int i = size - 1; i >= 1; i--)
        {
            swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
            adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
        }
    }
public:
    /*
    :param     N_K:         两个整数 [N,k]
    :param     data:        N 个人对应的楼层
    :return:   cost_time    花费时间
    */
    int function(vector<int> N_K, vector<int>data)
    {
        int cost_time = 0;
        int N = N_K[0];
        int K = N_K[1];

        //按楼层高低排序, 最高的一组先上，每组 K
        heapSort(data, data.size());
        while (K<data.size())
        {
            vector<int> data_pre_K(data.begin(), data.begin() + K);
            //一组所花费的时间为两倍到达最高楼层的时间： 
            cost_time = 2 * (data_pre_K[0] - 1);
            data.erase(data.begin(), data.begin() + K);
        }
        //判断是否还有剩余人员，有则乘电梯 
        if (0 < data.size())
        {
            cost_time += 2 * (data[0] - 1);
        }
        return cost_time;
    }
};

int main()
{
    vector<int> N_K = { 3,2};
    vector<int> data = { 3,2,4};
    Solution s;
    int result = s.function(N_K, data);
    cout << result << endl;
    return 0;
}