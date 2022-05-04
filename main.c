#include "smart_dim.h" 


#define lux_size 62
int lux_table[lux_size] = {
5,
6,
7,
8,
9,
10,
11,
12,
13,
14,
15,
16,
17,
19,
20,
21,
22,
24,
25,
27,
29,
30,
32,
34,
37,
39,
41,
44,
47,
50,
53,
56,
60,
64,
68,
72,
77,
82,
87,
93,
98,
105,
111,
119,
126,
134,
143,
152,
162,
172,
183,
195,
207,
220,
234,
249,
265,
282,
300,
316,
333,
360,
};

extern struct smartdim_conf *smart_get_conf_S6E8AA5X01_AMS520KT01(void);
int main() {
	struct smartdim_conf* conf = (struct smartdim_conf*)smart_get_conf_S6E8AA5X01_AMS520KT01();
	if(!conf) 
		printf("Error\n");
	char payload[GAMMA_SET_MAX] = {0};
	conf->lux_tab = lux_table;
	conf->lux_tabsize =  lux_size;
	conf->man_id = 3;
	conf->init(conf);

	for(int j = 0; j < lux_size; j++) {
		conf->generate_gamma(conf, lux_table[j], payload);
		printf("{ MCS_GAMMA, ");
		for(int i = 0; i < GAMMA_SET_MAX; i++) {
			printf("0x%02x, ", payload[i]);
		}
		printf("},\n");
	}
	return 0;
}
