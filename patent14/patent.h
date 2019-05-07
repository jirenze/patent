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
#include "json.h"

using namespace std;

class Patent
{
public:
	Patent();
	~Patent() {};

	/** 读取csv文件 */
	void ReadCSV();

	/** 写入json文件 */
	void WriteJson();
	
	/** 处理D值 */
	void ManageD();

	/** 处理R值 */
	void ManageR();

	/** 处理WZ值 */
	void ManageIndex();


private:
	/** 处理数据，结构体写入 */
	void PickCSVData();

	/** 写入各自的结构体 */
	void PickEveStruct();

	/** enum转换string */
	void EnumToString();

	/**--------- D -------*/
	/** 排序 */
	void SortForEveVector();

	/** 累加EVE */
	void TransferOfAccumulation();

	/** 计算差值D值 */
	void CalculateDifference();


	/**--------- R -------*/
	/** 计算各项指标的均值 */
	void CalculateAverage();

	/** 计算R值 */
	void CalculateRValue();

	/** 筛选R值 */
	void SelectRvalue();



	/**-------- Z ---------*/
	/** 循环处理指标 */
	void CalculateIndexForW();

	/** 循环处理除掉1个指标后的Z值计算数据结构 */
	void CalculateZFifter();

	/** 比较除掉指标后 剩下的指标 */
	void LeftoverIndex();



	
private:

	/** 计算R值 （工具）*/
	void CalculateRValueM(Enum_Patent in_enum_first, Enum_Patent in_enum_second, vector<RValueCL>& in_R_value);

	/** 筛选R值 (工具)*/
	void SelectRvalueM(vector<RValueCL>& in_R_value);

	/** 添加枚举，用于筛选 */
	void AddEnumPatent();

	/** 得到经过R值筛选后的D值的指标数据 */
	void SelectRafterD();


	/** 计算W 全指标 */
	void CalculateWValueFull(map<Enum_Patent, double>& in_w_data_fifter_for_z);

	/** 计算W 循环指标 */
	void CalculateWValueDelete(map<Enum_Patent, map<Enum_Patent, double>>& in_w_data);

	/** 计算Z，全指标 */
	void CalculateZValueFull(vector<Enum_Patent>& in_selected_enum_patent, vector<shared_ptr<Base_Struct>>& in_Z_fifter_full_vector, map<Enum_Patent, double>& in_w_data_fifter_for_z);

	/** 计算Z，循环指标 */
	void CalculateZValueDelete(vector<Enum_Patent>& in_selected_enum_patent, map<Enum_Patent, vector<shared_ptr<Base_Struct>>>& in_Z_fifter_delete_vector, map<Enum_Patent, map<Enum_Patent, double>>& in_w_data_fifter_for_all);

	/** 计算Z_total的D值，全指标 */
	void CalculateZtotalDFull(vector<shared_ptr<Base_Struct>>& in_Z_fifter_full_vector, shared_ptr<Transfer_Data>& in_Z_fifter_full_transfer);

	/** 计算Z_total的D值，循环指标 */
	void CalculateZtotalDDelete(map<Enum_Patent, shared_ptr<Transfer_Data>>& in_Z_fifter_delete_transfer, map<Enum_Patent, vector<shared_ptr<Base_Struct>>>& in_Z_fifter_delete_vector);

	/**------------- 序列化 -----------------*/

private: 
	/** 存储的string */
	vector<vector<string>> str_vector;

	/** enum转string */
	map<Enum_Patent, string> enum_to_string;

	/** 存储的所有数据 */
	vector<shared_ptr<Patent_Data_S>> patent_all_data;

	/**----------- D -------------*/

	/** 存储的所有数据 */
	map<Enum_Patent,vector<shared_ptr<Base_Struct>>> vector_base_struct_num;

	/** 总的transfer结构体数据 */
	map<Enum_Patent,shared_ptr<Transfer_Data>> transfer_all_data;

private:
	/**----------- R -------------*/

	/** 经过R值筛选后的D值transfer结构体数据 */
	map<Enum_Patent, shared_ptr<Transfer_Data>> transfer_after_data;

	/** 大于0.7 筛选剩下的指标 */
	vector<Enum_Patent> selected_enum_patent;
	/** 去掉的指标 */
	vector<Enum_Patent> pass_selected_enum_patent;

	/** 存储的所有枚举值 */
	vector<Enum_Patent> all_enum_patent;

	/** 初始化群编号数值 */
	const double temp_num_init = 1000.0f;

	/** 各项指标的均值 */
	map<Enum_Patent, double> R_average;

	/**-------- R值 ------*/
	/** 各项数据的R值 技术类 */
	vector<RValueCL> R_value_Technology;
	/** 各项数据的R值 引证类 */
	vector<RValueCL> R_value_Citation;
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

private:
	/**----------- Z -------------*/
	/** 筛选后的W值  用来计算没有去掉指标的Z值 */
	map<Enum_Patent, double> w_data_fifter_for_z;
	/** 筛选后的W值 顺序去掉指标 */
	map<Enum_Patent, map<Enum_Patent, double>> w_data_fifter_for_all;


	/** 筛选后Z的总值， 没有去掉指标 */
	vector<shared_ptr<Base_Struct>> Z_fifter_full_vector;
	/** 筛选后的 总的Z值 顺序去掉指标 */
	map<Enum_Patent, vector<shared_ptr<Base_Struct>>> Z_fifter_delete_vector;

	/** 总的Z值结构体数据 */
	shared_ptr<Transfer_Data> Z_fifter_full_transfer;
	/** 总的Z值结构体数据 顺序去掉指标 */
	map<Enum_Patent,shared_ptr<Transfer_Data>> Z_fifter_delete_transfer;

	/** 终止循环 */
	bool end_ok;

	/** json */
	Json::Value json_root;
};

