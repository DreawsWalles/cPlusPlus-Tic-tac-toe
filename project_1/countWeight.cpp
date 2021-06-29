#include "countWeight.h"

//!--������� ���� ����� ������

//�������� �� ����������� ��������� ������ � ��� ��� ��������
bool checkAttackplace(const int x, const int y,const int line,const int m)
{//+ �� ���, - ������ ���
//90-������ ��� �Y
//-90- �� ��� OY
//180- �� ��� OX
//-180-������ ��� OX
//45- �� �������� ���������
//-45- ������ �������� ���������
//135- �� ������� ���������
//-135- ������ ������� ���������
	switch (line)
	{
	case 90: 
		if ((y + 4) <= m)
			return true;
		else
			return false;
		break;
	case -90:
		if ((y - 4) >= 0)
			return true;
		else
			return false;
		break;
	case 180:
		if ((x + 4) <= m)
			return true;
		else
			return false;
		break;
	case -180:
		if ((x - 4) >= 0)
			return true;
		else
			return false;
		break;
	case -45:
		if (((x - 4) >= 0) && ((y + 4) <= m))
			return true;
		else 
			return false;
		break;
	case 45:
		if (((x + 4) <= m) && ((y - 4) >=0))
			return true;
		else
			return false;
		break;
	case 135:
		if (((x + 4) <= m) && (y + 4) <= m)
			return true;
		else
			return false;
		break;
	case -135:
		if (((x - 4) >=0) && (y - 4) >= 0)
			return true;
		else
			return false;
		break;
	}
}

//������� ���� ��� ����� ����� 
float countLine(const char fig, const int dx,const int dy, int x, int y,const int m, Cell** matr)
{
	int capability = 1;
	int potential = 0;
	float weight = 0;
	char curFig;
	Attack_Weight Attack;
	while ((capability <= 4) && (potential < 2) && (y>= 0) && (x>=0) && (y<=m) && (x<=m))
	{//�����
		curFig = matr[y][x].get_fig();
		if (fig == curFig)
			capability++;
		else
			if (curFig == '0')
				potential++;
			else
				return -1;
		x += dx;
		y += dy;
	}
	weight = Attack.get_weight(capability, potential);
	if ((capability >=4) && (potential>=1))
		weight *= 100;
	return weight;
}

//������� ���� ������ �� ���� ������������
float countWeight(Cell** matr,const int m,const int x,const int y,const char fig)
{
	int attack = 90;
	float weight = 0;
	float k;
	if (matr[y][x].check_attack(attack))
	{
		if (checkAttackplace(x, y, attack, m))
		{
			k = countLine(fig, 0, 1, x, y, m, matr);
			if ((k != -1) && (k != 2))
				weight += k;
		}
		else
			matr[y][x].set_attack(attack);
	}
	attack = -90;
	if (matr[y][x].check_attack(attack))
	{
		if (checkAttackplace(x, y, attack, m))
		{
			k = countLine(fig, 0, -1, x, y, m, matr);
			if ((k != -1) && (k != 2))
				weight += k;
		}
		else
			matr[y][x].set_attack(attack);
	}
	attack = 180;
	if (matr[y][x].check_attack(attack))
	{
		if (checkAttackplace(x, y, attack, m))
		{
			k = countLine(fig, 1, 0, x, y, m, matr);
			if ((k != -1) && (k != 2))
				weight += k;
		}
		else
			matr[y][x].set_attack(attack);
	}
	attack = -180;
	if (matr[y][x].check_attack(attack))
	{
		if (checkAttackplace(x, y, attack, m))
		{
			k = countLine(fig, -1, 0, x, y, m, matr);
			if ((k != -1) && (k != 2))
				weight += k;
		}
		else
			matr[y][x].set_attack(attack);
	}
	attack = 45;
	if (matr[y][x].check_attack(attack))
	{
		if (checkAttackplace(x, y, attack, m))
		{
			k = countLine(fig, 1, -1, x, y, m, matr);
			if ((k != -1) && (k != 2))
				weight += k;
		}
		else
			matr[y][x].set_attack(attack);
	}
	attack = -45;
	if (matr[y][x].check_attack(attack))
	{
		if (checkAttackplace(x, y, attack, m))
		{
			k = countLine(fig, -1, 1, x, y, m, matr);
			if ((k != -1) && (k != 2))
				weight += k;
		}
		else
			matr[y][x].set_attack(attack);
	}
	attack = 135;
	if (matr[y][x].check_attack(attack))
	{
		if (checkAttackplace(x, y, attack, m))
		{
			k = countLine(fig, 1, 1, x, y, m, matr);
			if ((k != -1) && (k != 2))
				weight += k;
		}
		else
			matr[y][x].set_attack(attack);
	}
	attack = -135;
	if (matr[y][x].check_attack(attack))
	{
		if (checkAttackplace(x, y, attack, m))
		{
			k = countLine(fig, -1, -1, x, y, m, matr);
			if ((k != -1) && (k != 2))
				weight += k;
		}
		else
			matr[y][x].set_attack(attack);
	}
	return weight;
}

int getEdge(const int coord,const int edge)
{
	switch (edge)
	{
	case 0:
		if ((coord - 5) >= edge)
			return (coord - 5);
		else
			return (coord - (coord - edge));
		break;
	default:
		if ((coord + 5) <= edge)
			return (coord + 5);
		else
			return (coord + (edge - coord));
		break;
	}
}