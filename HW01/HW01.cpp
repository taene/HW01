#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void Quick_sort(int left, int right);
int Partition(int left, int right);

void Swap(int a, int b)
{
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int Sum(int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float Avg(int size)
{
    return static_cast<float>(Sum(size)) / size;
}

void Asc(int size)
{
    // 선택 정렬
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }

        Swap(i, min);
    }
}

void Desc(int size)
{
    // 퀵 정렬
    Quick_sort(0, size - 1);
}

void Quick_sort(int left, int right)
{
    if (left >= right) return;

    int pivot = Partition(left, right);

    Quick_sort(left, pivot - 1);
    Quick_sort(pivot + 1, right);
}

int Partition(int left, int right)
{
    int pivot = arr[right];
    int pivot_index = right;

    right--;

    while (true)
    {
        // 내림차순
        while (arr[left] > pivot) left++;
        while (arr[right] < pivot) right--;

        if (left >= right) break;
        else
        {
            Swap(left, right);

            left++;
        }
    }

    Swap(left, pivot_index);

    return left;
}

int main()
{
    // 1번 과제 - 필수 기능
    int temp;

    cout << "입력할 숫자의 수를 입력하시오: ";
    int size;
    cin >> size;

    cout << "숫자 입력: ";
    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    cout <<"Sum: " << Sum(size) << ", Avg: " << Avg(size) << '\n';

    // 2번 과제 - 도전 기능
    cout << "=========================================\n";
    cout << "배열 정렬 선택 => 1: 오름차순, 2: 내림차순 \n";
    cin >> temp;

    if (temp == 1) Asc(size);
    else Desc(size);

    cout << "정렬한 배열: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
