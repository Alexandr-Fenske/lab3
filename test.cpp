#include "histogram.h"
#include <string>
#include <cassert>
#include "svg.h"
void test_positive() // ���� ������� ��� ������������� �����
{
    double min = 0;
    double max = 0;
    find_minmax({1,2,3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative() // ���� ������� ��� ������������� �����
{
    double min = 0;
    double max = 0;
    find_minmax({-1,-2,-3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void test_equal()  // ���� ������� ��� ���������� �����
{
    double min = 0;
    double max = 0;
    find_minmax({1,1,1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void test_one_number() // ���� �����
{
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void test_empty()  // ������ ���������
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}
void text_decoration() // ��������� ���� ��� ��������������� �������
{
   string k = text_decoration18(1);
   assert (k == "underline");
}
int main()
{
    test_positive();
    test_negative();
    test_equal();
    test_one_number();
    test_empty();
    text_decoration();

}
