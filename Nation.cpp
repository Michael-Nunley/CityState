#include "Nation.h"


Nation::Nation()
{
	NationName = "United States of America";
	NationsHistory = E_History::Voted_in;

	std::vector<float> local_History (MaxRecordedTime);
	for (int i = 0; i < 28; i++)
	{	
		for (int j = 0; j < MaxRecordedTime - 1; j++)
		{
			local_History[j] = (rand() % 10000)/10;
		}
		Stats[i] = { (E_StatNames)i, local_History, local_History[MaxRecordedTime - 2], 0,0 };
	}
}

Nation::Nation(char* Name, E_History History)
{
	NationName = Name;
	NationsHistory = History;

	std::vector<float> local_History (MaxRecordedTime);
	for (int i = 0; i < 28; i++)
	{
		for (int j = 0; j < MaxRecordedTime - 1; j++)
		{
			local_History[j] = (rand() % 10000) / 10;
		}
		Stats[i] = { (E_StatNames)i, local_History, local_History[MaxRecordedTime - 2], 0,0 };
	}
}


Nation::~Nation()
{

}

void Nation::SetStat(E_StatNames SelectedStat, S_Stat NewS_Stat)
{
	for (int i = 0; i < 28; i++)
	{
		if (SelectedStat == Stats[i].Name)
		{
			Stats[i] = NewS_Stat;
		}
	}
	return;
}


S_Stat Nation::GetStat(int stat)
{
	return Stats[stat];
}

void Nation::SetIndustryStat(E_Industrys SelectedStat, S_IndustryStat NewS_IndustryStat)
{
	for (int i = 0; i < 51; i++)
	{
		if (SelectedStat == IndStats[i].Name)
		{
			IndStats[i] = NewS_IndustryStat;
		}
	}
	return;
}

S_IndustryStat Nation::GetIndustryStat(int stat)
{
	return IndStats[stat];
}

char * Nation::GetNationName()
{
	return NationName;
}

E_History Nation::GetNationHistory()
{
	return NationsHistory;
}

void Nation::SetIndustryStat(S_Classification NewClassification)
{
	NationsClassification = NewClassification;
}

S_Classification Nation::GetNationsClassification()
{
	return NationsClassification;
}
