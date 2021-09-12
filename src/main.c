#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strcomp(char* c1,const char* c2)
{
	int i;
	if(strlen(c1) != strlen(c2)) return 0;
	for(i=0;i<strlen(c1);i++)
	{
		if(c1[i] != c2[i]) return 0;
	}
	return 1;
}
struct setting
{
	char name[100];
	char gouv[100];
	float freq;
};
struct setting new_setting(const char name[100],const float frq,const char gv)
{	
	struct setting set;
	strcpy(set.name,name);
	if(gv == 's')
		strcpy(set.gouv,"powersave");
	else if(gv == 'p')
		strcpy(set.gouv,"performance");
	set.freq = frq;
	return set;
}
void set_setting(struct setting set)
{
	char str[100];
	int i;
	for(i=0;i<8;i++)
	{
		sprintf(str,"sudo cpufreq-set -c %d -g %s -u %fGhz -r",i,set.gouv,set.freq);
		system(str);
	}

}
void print_setting(struct setting set)
{
	printf("name [%9s] gouv [%11s] freq [%1.1f] Ghz\n",set.name,set.gouv,set.freq);
}

int main(int narg,char** carg)
{
	struct setting list_setting[4];
	list_setting[0] = new_setting("mini",0.5,'s');
	list_setting[1] = new_setting("mini+",1.0,'p');
	list_setting[2] = new_setting("med",1.5,'p');
	list_setting[3] = new_setting("hard",2.5,'p');
	if(narg>1)
	{
		for(int i=0;i<(sizeof(list_setting)/sizeof(list_setting[0]));i++)
		{
			if(strcomp(carg[1],"help"))
			{
				print_setting(list_setting[i]);
			}
			else if(strcomp(carg[1],list_setting[i].name))
			{
				set_setting(list_setting[i]);
				break;
			}
		}
	
	}
	return 0;
}
