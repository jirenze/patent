#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <stdio.h>
#include <map>

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

	/** 添加transfer总的结构体 */
	void AddTransferStruct();

	/** 计算差值 */
	void CalculateDifference();

	/** 得到最大的D值 */
	vector<double> GetFirestMaxDIndex();

	/** 各项数据的D值 */
	vector<double> max_complete_socre;



private: 
	/** 存储的string */
	vector<vector<string>> str_vector;

	/** 存储的所有数据 */
	vector<shared_ptr<Patent_Data_S>> patent_all_data;

	/** 说明书页数 */
	vector<shared_ptr<Instruction_Num>> vector_instruction_num;

	/** 附图个数 */
	vector<shared_ptr<Image_Num>> vector_image_num;

	/** 文献引证数 */
	vector<shared_ptr<Non_Patent_Citation_Num>> vector_non_patent_citation_num;

	/** 专利引证数 */
	vector<shared_ptr<Citation_Num>> vector_citation_num;

	/** 引证本国专利数*/
	vector<shared_ptr<Citation_Of_Domestic_Num>> vector_citation_of_domestic_num;

	/** 引证外国专利数 */
	vector<shared_ptr<Citation_Of_Foreign_Num>> vector_citation_of_foreign_num;

	/** 专利类别 */
	vector<shared_ptr<Patent_Type>> vector_patent_type;

	/** 保护期 */
	vector<shared_ptr<Term_Of_Patent_Protection>> vector_term_of_patent_protection;

	/** 分类数 */
	vector<shared_ptr<Classify_Num>> vector_classify_num;

	/** IPC大类数 */
	vector<shared_ptr<IPC_Large_Classify_Num>> vector_IPC_large_classify_num;

	/** IPC小类数 */
	vector<shared_ptr<IPC_Sub_Classify_Num>> vector_IPC_sub_classify_num;

	/** 同族专利数 */
	vector<shared_ptr<Kin_Num>> vector_kin_num;

	/** 同族布局国家、地区数 */
	vector<shared_ptr<Kin_Of_Country_Num>> vector_kin_of_country_num;

	/** 是否为PCT申请 */
	vector<shared_ptr<PCT_Apply>> vector_PCT_apply;

	/** 是否为五国专利/四方专利 */
	vector<shared_ptr<Five_Four_Countries_Patent>> vector_five_four_countries_patent;

	/** 专利国别代码 */
	vector<shared_ptr<Country_code>>  vector_country_code;

	/** 申请日公开日时间间隔（年）*/
	vector<shared_ptr<Application_Open_Day_Interval>> vector_application_open_day_interval;

	/** 申请日授权日时间间隔 */
	vector<shared_ptr<Application_Authorization_Day_Interval>> vector_application_authorization_day_interval;

	/** 公开日授权日时间间隔 */
	vector<shared_ptr<Open_Authorization_Day_Interval>> vector_open_authorization_day_interval;

	/** 剩余有效期 */
	vector<shared_ptr<Survival_Time>> vector_survival_time;

	/** 是否有优先权 */
	vector<shared_ptr<PRORITY>> vector_prority;

	/** 权项数 */
	vector<shared_ptr<Right_Num>> vector_right_num;

	/** 发明人数 */
	vector<shared_ptr<Num_Of_Invention>> vector_num_of_invention;

	/** 申请人数 */
	vector<shared_ptr<Num_Of_Application>> vector_num_of_application;

	/** 当前专利权人数 */
	vector<shared_ptr<Current_Num_Of_Patent>> vector_current_num_of_patent;

	/** 申请人类型 */
	vector<shared_ptr<Type_Of_Application>> vector_type_of_application;

	






	/** 说明书页数 */
	shared_ptr<Transfer_Data> instruction_num_transfer;

	/** 附图个数 */
	shared_ptr<Transfer_Data> image_num_transfer;

	/** 文献引证数 */
	shared_ptr<Transfer_Data> non_patent_citation_num_transfer;

	/** 专利引证数 */
	shared_ptr<Transfer_Data> citation_num_transfer;

	/** 引证本国专利数*/
	shared_ptr<Transfer_Data> citation_of_domestic_num_transfer;

	/** 引证外国专利数 */
	shared_ptr<Transfer_Data> citation_of_foreign_num_transfer;

	/** 专利类别 */
	shared_ptr<Transfer_Data> patent_type_transfer;

	/** 保护期 */
	shared_ptr<Transfer_Data> term_of_patent_protection_transfer;

	/** 分类数 */
	shared_ptr<Transfer_Data>  classify_num_transfer;

	/** IPC大类数 */
	shared_ptr<Transfer_Data> IPC_large_classify_num_transfer;

	/** IPC小类数 */
	shared_ptr<Transfer_Data> IPC_sub_classify_num_transfer;

	/** 同族专利数 */
	shared_ptr<Transfer_Data> kin_num_transfer;

	/** 同族布局国家、地区数 */
	shared_ptr<Transfer_Data> kin_of_country_num_transfer;

	/** 是否为PCT申请 */
	shared_ptr<Transfer_Data> PCT_apply_transfer;

	/** 是否为五国专利/四方专利 */
	shared_ptr<Transfer_Data> five_four_countries_patent_transfer;

	/** 专利国别代码 */
	shared_ptr<Transfer_Data> country_code_transfer;

	/** 申请日公开日时间间隔（年）*/
	shared_ptr<Transfer_Data> application_open_day_interval_transfer;

	/** 申请日授权日时间间隔 */
	shared_ptr<Transfer_Data> application_authorization_day_interval_transfer;

	/** 公开日授权日时间间隔 */
	shared_ptr<Transfer_Data> open_authorization_day_interval_transfer;

	/** 剩余有效期 */
	shared_ptr<Transfer_Data> survival_time_transfer;

	/** 是否有优先权 */
	shared_ptr<Transfer_Data> prority_transfer;

	/** 权项数 */
	shared_ptr<Transfer_Data> right_num_transfer;

	/** 发明人数 */
	shared_ptr<Transfer_Data> num_of_invention_transfer;

	/** 申请人数 */
	shared_ptr<Transfer_Data> num_of_application_transfer;

	/** 当前专利权人数 */
	shared_ptr<Transfer_Data> current_num_of_patent_transfer;

	/** 申请人类型 */
	shared_ptr<Transfer_Data> type_of_application_transfer;

	/** 总的transfer结构体数据 */
	vector<shared_ptr<Transfer_Data>> transfer_all_data;

	/** 初始化群编号数值 */
	const double temp_num_init = 1000.0f;
};
