// 
// ok
// 

#include "Technique.h"

void Technique::stir() {
	// �߰��ؾ��� (�̵�, led, oled, ��ǰ��)

}

void Technique::build() {
	// �߰��ؾ��� (�̵�, led, oled)
}

void Technique::f(TechniqueMethod method) {

	switch (method) {
	case TechniqueMethod::BUILD:
		build();
	case TechniqueMethod::STIR:
		stir();
	}

}

