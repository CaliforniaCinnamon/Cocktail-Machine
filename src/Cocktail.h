// Cocktail.h

#if 0
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
	


	/* pseudo code

	name
	disp material : amount (array)
	pump material : amount (array)
	technique method

	*/

	// TechniqueMethod method; // ������ ���� �� ������ Technique ��� ��Ŭ��� �ϸ� �� ����



public:

	/*************������*****************/
	//Ĭ���� ������ �� �� �ٸ���_�����ʿ�
	//Ĭ���� ����: ���ø�Ƽ��,��ī��,����Ͽ���,���θ���,�ڽ�������ź,��Ű��,�ع�,���Ϸ���,������Ÿ,�����,������,��ġũ����,��ũ������̺�,�ú긮��,��Ƽ����,�����󼱶�����,Ÿ��Ʋ���÷���,���ݸ���
	//disp ����: ����ī,��,ȭ��Ʈ��,������,���Ʈ��,���̳����׸�����,�׸����,��ġ,���ť���,ī�ý�,������,��ٴϿ����
	Material m_disp[15][10] = { {20,30,40,0,0,0},{},{},{},{},{},{},{} };
	//15���� Ĭ����, 7���� ���(pump)_���������ʿ�
	//pump ����: �����,����,�����ֽ�,�����ػ���,�������ֽ�,�ڸ��ֽ�,��п���
	int m_pump[15][7] = { {},{} };
	
	//Ĭ���� �̸� �迭
	char* cocktail_name = { "applemartini" };
	//disp_material �̸� �迭
	char* disp_material_name = { "sdf" };
	//pump_material �̸� �迭
	char* pump_material_name = { "sdfsdf" }


	/* pseudo code

	constructor
	get disp recipe
	get pump recipe
	get name
	get technique

	*/

};

#endif