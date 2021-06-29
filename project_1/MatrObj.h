#pragma once
// ����� ��� �������� ������� �� �������� ������. ������: ����� ������������� ����, ��������� ������������� ���� ��� �������� � ��� ������, ���������� ����� ��� ��������� ����� ������
#include "Cell.h"
#include "countWeight.h"
#include "interface.h"
#include "CheckWin.h"

class MatrObj :
    public Cell
{
private:
    Cell** _matr;
    int _size;
    int _x, _y;
    COORD _winCombinate[5];
public:
    MatrObj(int size);
    ~MatrObj();
    bool checkWin(int x, int y);
    void printMatr();  
    void printMatrWin();
    char get_fig(int x, int y);
    COORD get_weight(); //������� ���������� ����� � ������������ ����� 
    void calculation(int x, int y, char fig); //������� ���� ��� ������� 11*11, ��� x � y ���������� ����������� ������, ������� �� ���������
    void print_weight(char);
private:
    void setWinCell(COORD a[5]);
    void x_vs_o(); //������� ������������ ��� ��� �������� ��� ������
    void sort();
};

