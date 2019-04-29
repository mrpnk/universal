#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <posit_c_api.h>

// enumerate all addition cases for a posit configuration
int ValidateAddition(char* tag) {
	const int NR_POSITS = 256;
	int nrOfFailedTests = 0;
	posit8_t pa, pb, pc;

	nrOfFailedTests = 0;
	for (int a = 0; a < NR_POSITS; ++a) {
		pa = posit8_reinterpret(a);
		for (int b = 0; b < NR_POSITS; ++b) {
			pb = posit8_reinterpret(b);
			pc = posit8_addp8(pa, pb);
			float da, db, dref;
			da = posit8_tof(pa);
			db = posit8_tof(pb);
			dref = da + db;
			posit8_t pref = posit8_fromf(dref);
			if (posit8_cmp(pref, pc)) {
				printf("FAIL: 8.0x%02xp - 8.0x%02xp produced 8.0x%02xp instead of 8.0x%02xp\n",
					posit8_bits(pa), posit8_bits(pb), posit8_bits(pc), posit8_bits(pref));
				++nrOfFailedTests;
			}
		}
	}
	if (nrOfFailedTests) {
		printf("subtraction     FAIL\n");
		}
	else {
		printf("subtraction     PASS\n");
	}

	return nrOfFailedTests;
}

int ValidateSubtraction(char* tag) {
	const int NR_POSITS = 256;
	int nrOfFailedTests = 0;
	posit8_t pa, pb, pc;

	nrOfFailedTests = 0;
	for (int a = 0; a < NR_POSITS; ++a) {
		pa = posit8_reinterpret(a);
		for (int b = 0; b < NR_POSITS; ++b) {
			pb = posit8_reinterpret(b);
			pc = posit8_subp8(pa, pb);
			float da, db, dref;
			da = posit8_tof(pa);
			db = posit8_tof(pb);
			dref = da - db;
			posit8_t pref = posit8_fromf(dref);
			if (posit8_cmp(pref, pc)) {
				printf("FAIL: 8.0x%02xp - 8.0x%02xp produced 8.0x%02xp instead of 8.0x%02xp\n",
					posit8_bits(pa), posit8_bits(pb), posit8_bits(pc), posit8_bits(pref));
				++nrOfFailedTests;
			}
		}
	}
	if (nrOfFailedTests) {
		printf("subtraction     FAIL\n");
	}
	else {
		printf("subtraction     PASS\n");
	}

	return nrOfFailedTests;
}

void TestCaseAdd(posit8_t pa, posit8_t pb) {
	posit8_t pc, pref;
	float fa = posit8_tof(pa);
	float fb = posit8_tof(pb);
	pref = posit8_fromf(fa + fb);
	pc = posit8_addp8(pa, pb);
	printf("pref = 0x%02x 0x%02x = presult\n", pref.v, pc.v);
}

void TestCaseSub(posit8_t pa, posit8_t pb) {
	posit8_t pc, pref;
	float fa = posit8_tof(pa);
	float fb = posit8_tof(pb);
	pref = posit8_fromf(fa - fb);
	pc = posit8_subp8(pa, pb);
	printf("pref = 0x%02x 0x%02x = presult\n", pref.v, pc.v);
}

void TestCaseMul(posit8_t pa, posit8_t pb) {
	posit8_t pc, pref;
	float fa = posit8_tof(pa);
	float fb = posit8_tof(pb);
	pref = posit8_fromf(fa * fb);
	pc = posit8_mulp8(pa, pb);
	printf("pref = 0x%02x 0x%02x = presult\n", pref.v, pc.v);
}

void TestCaseDiv(posit8_t pa, posit8_t pb) {
	posit8_t pc, pref;
	float fa = posit8_tof(pa);
	float fb = posit8_tof(pb);
	pref = posit8_fromf(fa / fb);
	pc = posit8_divp8(pa, pb);
	printf("pref = 0x%02x 0x%02x = presult\n", pref.v, pc.v);
}

int main(int argc, char* argv[]) 
{
	posit8_t pa, pb;

	pa.v = 0x00;
	pb.v = 0x80;

	printf("sqrt(0) = %f\n", sqrt(0.0));
}
