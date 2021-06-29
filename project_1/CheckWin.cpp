#include "CheckWin.h"
//��������� ����� �� ������� � ����� ����������� 
bool CheckWinLine(Cell** matr, int x, int y, const int dx, const int dy, COORD(&a)[5], int& count, const int m)//�������� count ������ ����� ���������� �������� 0
{
	bool ok = true;
	char fig = matr[y][x].get_fig();
	while ((count < 5) && (y >= 0) && (x >= 0) && (y <= m) && (x <= m) && ok)
	{
		if (fig == matr[y][x].get_fig())
		{
			a[count].X = x;
			a[count].Y = y;
			count++;
		}
		else
			ok = false;
		y += dy;
		x += dx;
	}
	return count == 5;
}

//����������� ��������� ���� � ���������� ��� ���������
COORD ToCoord(const int deg)
{
//90-������ ��� �Y
//-90- �� ��� OY
//180- �� ��� OX
//-180-������ ��� OX
//45- �� �������� ���������
//-45- ������ �������� ���������
//135- �� ������� ���������
//-135- ������ ������� ���������
	COORD a;
	switch (deg)
	{
	case 90: 
		a.X = 0;
		a.Y = 1;
		return a;
	case -90:
		a.X = 0;
		a.Y = -1;
		return a;
	case 180:
		a.X = 1;
		a.Y = 0;
		return a;
	case -180:
		a.X = -1;
		a.Y = 0;
		return a;
	case 45:
		a.X = 1;
		a.Y = -1;
		return a;
	case -45:
		a.X = -1;
		a.Y = 1;
		return a;
	case 135:
		a.X = 1;
		a.Y = 1;
		return a;
	case - 135:
		a.X = -1;
		a.Y = -1;
		return a;
	}
}

//��������� ����� �� ������� � ���� ������������
bool CheckWin(Cell** matr, const int x, const int y, const int line, const int m, COORD (&winCombinate)[5])
{
	COORD a;
	COORD WinCombinate1[5], WinCombinate2[5];
	int count1 = 0, count2 = 0;
	a = ToCoord(line);
	if (!CheckWinLine(matr, x, y, a.X, a.Y, WinCombinate1, count1, m))
	{
		a = ToCoord(-line);
		if (CheckWinLine(matr, x, y, a.X, a.Y, WinCombinate2, count2, m))
			for (int i = 0; i < count2; i++)
			{
				winCombinate[i] = WinCombinate2[i];
				return true;
			}
		else
			if ((count1 + count2) >= 6)
			{
				int n;
				for (n = 0; n < count2; n++)
					winCombinate[n] = WinCombinate2[n];
				for (int i = 0; i < count1; i++)
				{
					winCombinate[n] = WinCombinate1[n];
					n++;
				}
				return true;
			}
	}
	else
	{
		for (int i = 0; i < count1; i++)
			winCombinate[i] = WinCombinate1[i];
		return true;
	}
	return false;
}
