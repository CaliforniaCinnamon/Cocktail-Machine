// Cocktail.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#include "Material.h"
#include "Technique.h"


class Cocktail
{
private:
    String cocktail_name; // Ĭ���� �̸�
  // {0, 0, 50, 60, 0, 0, 0, ...} �̷� ������ �ʿ��� ���� �� ������ ������.
    int disp_material_amount[12];
    int pump_material_amount[7];
    TechniqueMethod method; // ���
    int cocktail_rgb[3]; // �ϼ����� �� Led ���� ����

public:
    // �̸��� "Martini" �̷��� �ް�, �迭�� �ּҷ� ����. ����� BUILD STIR �̷��� ���ָ� ��.
    Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],
        TechniqueMethod a_method, int a_r, int a_g, int a_b);

    String get_name() { return cocktail_name; }
    int* get_disp_recipe() { return disp_material_amount; }
    int* get_pump_recipe() { return pump_material_amount; }
    TechniqueMethod get_technique() { return method; }
    int* get_cocktail_color() { return cocktail_rgb; }

};


Cocktail::Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],
    TechniqueMethod a_method, int a_r, int a_g, int a_b)
{
    cocktail_name = name;

    for (int i = 0; i < 12; i++) { // ���漭 ��� ������ �� ���� ��������
        disp_material_amount[i] = a_disp_mtrl[i];
    }

    for (int i = 0; i < 7; i++) { // ���� ��� ������ �� ���� ��������
        pump_material_amount[i] = a_pump_mtrl[i];
    }

    cocktail_rgb[0] = a_r;
    cocktail_rgb[1] = a_g;
    cocktail_rgb[2] = a_b;

    method = a_method;
}


#endif



