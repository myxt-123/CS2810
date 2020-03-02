#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Student
{
public:
    int m[5];
    int skill;
    int rank;
};

class List
{
public:
    vector<Student> list;

    void insert(Student stu)
    {
        if (list.size() == 0)
        {
            list.push_back(stu);
            return;
        }

        bool flag = false;
        for (int i = 0; i < list.size(); i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (stu.m[j] < list[i].m[j])
                    break;
                else if (stu.m[j] > list[i].m[j])
                {
                    list.insert(list.begin() + i, stu);
                    flag = true;
                    return;
                }
            }
        }
        if (flag == false)
            list.push_back(stu);
    };

    void updateRanks()
    {
        for (int i = 0; i < list.size(); i++)
            list[i].rank = i + 1;
    };

    long long mergeSort(int left, int right)
    {
        int mid = (left + right) / 2;
        if (left == right){
            return 0;
        }
        if (right - left == 1){
            if (list[left].skill < list[right].skill)
            {
                Student temp = list[left];
                list[left] = list[right];
                list[right] = temp;
                return 1;
            }
            return 0;
        }
        long long count1 = mergeSort(left, mid);
        long long count2 = mergeSort(mid + 1, right);
        long long count3 = merge(left, right);
        return count1 + count2 + count3;
    }

    long long merge(int left, int right)
    {
        Student temp[right - left + 1];
        long long count = 0;
        int i = 0;
        int i1 = left;
        int mid = (left + right) / 2;
        int i2 = mid + 1;
        while (i1 < mid + 1 || i2 < right + 1)
        {
            if (list[i2].skill > list[i1].skill)
            {
                temp[i] = list[i2];
                count = count + mid - i1 + 1;
                ++i2;
                ++i;
            }
            else if (list[i2].skill <= list[i1].skill)
            {
                temp[i] = list[i1];
                ++i1;
                ++i;
            }
        }
        if (i1 == mid + 1)
        {
            for (int j = i2; j < right + 1; ++j, ++i)
            {
                temp[i] = list[j];
            }
        }
        else if (i2 == right + 1)
        {
            for (int j = i1; j < mid + 1; ++j, ++i)
            {
                temp[i] = list[j];
            }
        }
        for (int j = 0; j < right - left + 1; ++j)
        {
            list[left + j] = temp[j];
        } 
        return count;
    }
};

int main()
{
    int n;
    List students;
    cin >> n;
    long long count = 0;
    for (int i = 0; i < n; ++i)
    {
        Student temp;
        cin >> temp.m[0] >> temp.m[1] >> temp.m[2] >> temp.m[3] >> temp.m[4] >> temp.skill;
        students.insert(temp);
    }

    cout << students.mergeSort(0, n-1);
    
    return 0;
}