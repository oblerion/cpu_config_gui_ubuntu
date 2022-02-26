#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
struct setting
{
	std::string name="";
	std::string gouv="";
	int freq=0;
	setting(std::string name,const int frq,const char gv)
	{
		this->name=name;
		if(gv == 's')
			this->gouv="powersave";
		else if(gv == 'p')
			this->gouv="performance";
		this->freq = frq;
	}
	void set()
	{
		std::string str;
		int i;
		for(i=0;i<8;i++)
		{
			str = "sudo cpufreq-set -c "+std::to_string(i)+" -g "+this->gouv+" -u "+std::to_string((float)this->freq/1000)+" -r";
			system(str.c_str());
		}

	}
	void print()
	{
		printf("name [%9s] gouv [%11s] freq [%1.1f] Ghz\n",this->name.c_str(),this->gouv.c_str(),(float)this->freq/1000);
	}

};


int main()
{
	int i;
	const char nbsetting = 4;
	std::vector<struct setting> list_setting={
		*(new struct setting("mini",500,'s')),
		*(new struct setting("mini+",1000,'p')),
		*(new struct setting("med",1500,'p')),
		*(new struct setting("hard",2500,'p'))
	};
	
	char choix='n';
	printf(":: cpucfg :: start\n");
	while(choix != 'a' &&
		choix != 'z' &&
		choix != 'e' &&
		choix != 'r')
	{
		for(i=0;i<nbsetting;i++)
		{
			switch(i)
			{
				case 0: printf("a ");
				break;
				case 1: printf("z ");
				break;
				case 2: printf("e ");
				break;
				case 3: printf("r ");
				default: ;
			}
			list_setting[i].print();
		}
		choix=getchar();
		switch(choix)
		{
			case 'a': 
				list_setting[0].set();
				list_setting[0].print();
			break;
			case 'z': 
				list_setting[1].set();
				list_setting[1].print();
			break;
			case 'e': 
				list_setting[2].set();
				list_setting[2].print();
			break;
			case 'r': 
				list_setting[3].set();
				list_setting[3].print();
			default: ;
		}
	}
	printf(":: cpucfg :: end\n");
	return 0;
}
