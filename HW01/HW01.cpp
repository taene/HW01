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
    // ���� ����
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
    // �� ����
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
        // ��������
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
    // 1�� ���� - �ʼ� ���
    int temp;

    cout << "�Է��� ������ ���� �Է��Ͻÿ�: ";
    int size;
    cin >> size;

    cout << "���� �Է�: ";
    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    cout <<"Sum: " << Sum(size) << ", Avg: " << Avg(size) << '\n';

    // 2�� ���� - ���� ���
    cout << "=========================================\n";
    cout << "�迭 ���� ���� => 1: ��������, 2: �������� \n";
    cin >> temp;

    if (temp == 1) Asc(size);
    else Desc(size);

    cout << "������ �迭: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
