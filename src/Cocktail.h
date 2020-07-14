// Cocktail.h

#ifndef _COCKTAIL_h
#define _COCKTAIL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "Material.h"
#include "Technique.h"
using namespace std;


class Cocktail
{
private:
	string name;
	map<DispenserMaterial, double> disp_recipe;
	map<PumpMaterial, double> pump_recipe;
	TechniqueMethod method;

	// ��ȯ�Լ�
	// map<Material, double> vector_to_map(vector<string> a_list);

public: // ���ͷ� �� ���� ���� ���� ���� ������ map�� �������.
	Cocktail(string a_name,
		TechniqueMethod a_method,
		map<DispenserMaterial, double> a_disp_recipe,
		map<PumpMaterial, double> a_pump_recipe)
	{
		name = a_name;
		method = a_method;
		disp_recipe = a_disp_recipe;
		pump_recipe = a_pump_recipe;
	}


	map<DispenserMaterial, double> get_disp_recipe() { return disp_recipe; }
	map<PumpMaterial, double> get_pump_recipe() { return pump_recipe; }
	string get_name() { return name; }
	TechniqueMethod get_craft_method() { return method; }

#endif

