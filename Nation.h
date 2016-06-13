#pragma once

#define MaxRecordedTime 87600 //number of hours in 10 years
//#define MaxRecordedTime 5256000 //number of minutes in 10 years

#include <tchar.h>
#include <ctype.h>          // toupper, isprint
#include <math.h>           // sqrtf, fabsf, fmodf, powf, cosf, sinf, floorf, ceilf
#include <stdio.h>          // vsnprintf, sscanf, printf
#include <stdlib.h>         // NULL, malloc, free, qsort, atoi
#include <vector>
#include <map>
#include <iostream>

enum class E_Industrys
{
	Accommodations,
	Accounting,
	Advertising,
	Aerospace,
	Agriculture_and_Agribusiness,
	Air_Transportation,
	Apparel_and_Accessories,
	Auto,
	Banking,
	Beauty_and_Cosmetics,
	Biotechnology,
	Chemical,
	Communications,
	Computer,
	Construction,
	Consulting,
	Consumer_Products,
	Education,
	Electronics,
	Employment,
	Energy,
	Entertainment_and_Recreation,
	Fashion,
	Financial_Services,
	Food_and_Beverage,
	Health,
	Information,
	Information_Technology,
	Insurance,
	Journalism_and_News,
	Legal_Services,
	Manufacturing,
	Media_and_Broadcasting,
	Medical_Devices_and_Supplies,
	Motion_Pictures_and_Video,
	Music,
	Pharmaceutical,
	Public_Administration,
	Public_Relations,
	Publishing,
	Real_Estate,
	Retail,
	Service,
	Sports,
	Technology,
	Telecommunications,
	Tourism,
	Transportation,
	Travel,
	Utilities,
	Video_Game,
	Web_Services
};

enum class E_StatNames
{
	//Basics
	Population,
	GDP,
	Employment,
	Taxation,
	//Chosen
	Civil_Rights,
	Political_Rights,
	Economic_Rights,
	//Self
	Defense_Forces,
	Public_Healthcare,
	Public_Transportation,
	Public_Safety,
	Public_Welfare,
	//Ranking internal
	Corruption,
	Culture,
	Ecology,
	Environment,
	Health,
	Human_Development_Index,
	Income_Equality,
	Intelligence,
	Lifespan,
	Business_Subsidization,
	Pro_Market_Policies,
	Tourism,
	Toxicity,
	Weaponization,
	Religiousness,
	Crime,
	Scientific_Advancement
};

inline char* E_StatNamesToChar(E_StatNames StatName) {
	switch (StatName)
	{
		default:
		{
			throw std::invalid_argument("Invalid Section value");
			break;
		}
		case E_StatNames::Population:
		{
			return "Population";
			break;
		}
		case E_StatNames::GDP:
		{
			return "GDP";
			break;
		}
		case E_StatNames::Employment:
		{
			return "Employment";
			break;
		}
		case E_StatNames::Taxation:
		{
			return "Taxation";
			break;
		}
		case E_StatNames::Civil_Rights:
		{
			return "Civil Rights";
			break;
		}
		case E_StatNames::Political_Rights:
		{
			return "Political Rights";
			break;
		}
		case E_StatNames::Economic_Rights:
		{
			return "Economic Rights";
			break;
		}
		case E_StatNames::Defense_Forces:
		{
			return "Defense Forces";
			break;
		}
		case E_StatNames::Public_Healthcare:
		{
			return "Public Healthcare";
			break;
		}
		case E_StatNames::Public_Transportation:
		{
			return "Public Transportation";
			break;
		}
		case E_StatNames::Public_Safety:
		{
			return "Public Safety";
			break;
		}
		case E_StatNames::Public_Welfare:
		{
			return "Public Welfare";
			break;
		}
		case E_StatNames::Corruption:
		{
			return "Corruption";
			break;
		}
		case E_StatNames::Culture:
		{
			return "Culture";
			break;
		}
		case E_StatNames::Ecology:
		{
			return "Ecology";
			break;
		}
		case E_StatNames::Environment:
		{
			return "Environment";
			break;
		}
		case E_StatNames::Health:
		{
			return "Health";
			break;
		}
		case E_StatNames::Human_Development_Index:
		{
			return "Human Development Index";
			break;
		}
		case E_StatNames::Income_Equality:
		{
			return "Income Equality";
			break;
		}
		case E_StatNames::Intelligence:
		{
			return "Intelligence";
			break;
		}
		case E_StatNames::Lifespan:
		{
			return "Lifespan";
			break;
		}
		case E_StatNames::Business_Subsidization:
		{
			return "Business Subsidization";
			break;
		}
		case E_StatNames::Pro_Market_Policies:
		{
			return "Pro Market Policies";
			break;
		}
		case E_StatNames::Tourism:
		{
			return "Tourism";
			break;
		}
		case E_StatNames::Toxicity:
		{
			return "Toxicity";
			break;
		}
		case E_StatNames::Weaponization:
		{
			return "Weaponization";
			break;
		}
		case E_StatNames::Religiousness:
		{
			return "Religiousness";
			break;
		}
		case E_StatNames::Crime:
		{
			return "Crime";
			break;
		}
		case E_StatNames::Scientific_Advancement:
		{
			return "Scientific Advancement";
			break;
		}

	}
}


struct S_Stat
{
	E_StatNames Name;
	std::vector<float> AmountHistory;
	float CurrentAmount;
	unsigned int rank_region;
	unsigned int rank_global;
};

struct S_IndustryStat
{
	E_Industrys Name;
	std::vector<float> AmountHistory;
	float CurrentAmount;
	unsigned int rank_region;
	unsigned int rank_global;
};

enum class E_History
{
	Military_Coo, //Come to power with little freedoms
	Voted_in, //
};

enum class E_PoliticalCategory
{
	Authoritarian,
	Democratic,
	Monarchy,
	Oligarchy,

};

enum class E_EconomicCategory
{

};

enum class E_CivilCategory
{

};

struct S_Classification
{
	E_PoliticalCategory PoliticalType;
	float PoliticalRange;
	E_EconomicCategory EconomicType;
	float EconomicRange;
	E_CivilCategory CivilType;
	float CivilRange;
};

class Nation
{
public:
	Nation();
	Nation(char* Name, E_History History);
	~Nation();

	void SetStat(E_StatNames SelectedStat, S_Stat NewS_Stat);
	S_Stat GetStat(int stat);

	void SetIndustryStat(E_Industrys SelectedStat, S_IndustryStat NewS_IndustryStat);
	S_IndustryStat GetIndustryStat(int stat);

	void SetIndustryStat(S_Classification NewClassification);
	S_Classification GetNationsClassification();

	char* GetNationName();
	E_History GetNationHistory();
	

protected:
	char* NationName;
	E_History NationsHistory;

private:
	S_Stat Stats[28];
	S_IndustryStat IndStats[51];
	S_Classification NationsClassification;

};