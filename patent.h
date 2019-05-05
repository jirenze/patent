#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <stdio.h>
#include <map>
#include <set>

#include "PatentStruct.h"
#include "patent.h"
	
using namespace std;

class Patent
{
public:
	Patent();
	~Patent() {};

	/** 读取csv文件 */
	void ReadCSV();
	/** 写入csv文件 */
	void WriteCSV();
	/** 处理数据，结构体写入 */
	void PickCSVData();

	/** 写入各自的结构体 */
	void PickEveStruct();

	/** 排序 */
	void SortForEveVector();

	/** 累加EVE */
	void TransferOfAccumulation();

	/** 计算差值 */
	void CalculateDifference();

	/** 计算各项指标的均值 */
	void CalculateAverage();

	/** 计算R值 */
	void CalculateRValue();

	/** 筛选R值 */
	void SelectRvalue();
	
	/** 得到经过R值筛选后的D值的指标数据 */
	void SelectRafterD();

	/** 计算W */
	void CalculateWValue();

	/** 计算Z */
	void CalculateZValue();
public: 
	/** 得到最大的D值 */
	vector<double> GetFirestMaxDIndex();
	/** 各项数据的D值 */
	vector<double> max_complete_socre;
	/** 各项指标的均值 */
	map<Enum_Patent, double> R_average;


	/**-------- R值 ------*/
	/** 各项数据的R值 技术类 */
	vector<RValueCL> R_value_Technology;
	/** 各项数据的R值 IPC */
	vector<RValueCL> R_value_IPC;
	/** 各项数据的R值 国际化 */
	vector<RValueCL> R_value_Internationalization;
	/** 各项数据的R值 时间 */
	vector<RValueCL> R_value_Time;
	/** 各项数据的R值 权利类 */
	vector<RValueCL> R_value_Right;
	/** 各项数据的R值 发明人 申请人 */
	vector<RValueCL> R_value_Inventor;
	
	/** 大于0.7 筛选剩下的指标 */
	vector<Enum_Patent> selected_enum_patent;
private:

	/** 计算R值 （工具）*/
	void CalculateRValueM(Enum_Patent in_enum_first, Enum_Patent in_enum_second, vector<RValueCL>& in_R_value);

	/** 筛选R值 (工具)*/
	void SelectRvalueM(vector<RValueCL>& in_R_value);

	/** 添加枚举，用于筛选 */
	void AddEnumPatent();


private: 
	/** 存储的string */
	vector<vector<string>> str_vector;

	/** 存储的所有数据 */
	vector<shared_ptr<Patent_Data_S>> patent_all_data;

	/** 存储的所有数据 */
	map<Enum_Patent,vector<shared_ptr<Base_Struct>>> vector_base_struct_num;

	/** 总的transfer结构体数据 */
	map<Enum_Patent,shared_ptr<Transfer_Data>> transfer_all_data;

	/** 经过R值筛选后的D值transfer结构体数据 */
	map<Enum_Patent, shared_ptr<Transfer_Data>> transfer_after_data;

	/** w总的权重 */
	map<Enum_Patent, double> w_data;




	/** 存储的所有枚举值 */
	vector<Enum_Patent> all_enum_patent;

	/** 初始化群编号数值 */
	const double temp_num_init = 1000.0f;
};

