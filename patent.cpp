#include "patent.h"

Patent::Patent()
{

}

void Patent::ReadCSV()
{
	/** 打开文件 */
	ifstream in_file("C:\\Users\\jiren\\Desktop\\patent18\\patentnow.csv", ios::in);
	string temp_line_str;

	/** 检测能否打开 */
	if (!in_file.is_open())
	{
		cout << "Notice! the file is loaded unsuccessfully!" << endl;
		return;
	}
	else
	{
		cout << "The file is loaded successfully and the file is being read........" << endl;
	}

	while (getline(in_file, temp_line_str))
	{
		/** 存成二维结构 */
		stringstream ss(temp_line_str);
		string str;
		vector<string> line_vector;

		while (getline(ss, str, ','))
		{
			line_vector.push_back(str);
		}
		str_vector.push_back(line_vector);
	}
}

void Patent::WriteCSV()
{
	/** 写文件 */
	ofstream out_file("C:\\Users\\jiren\\Desktop\\patent18\\out.csv", ios::out);
	out_file.precision(12);

	out_file << "instruction_num" << ','
		<< "image_num" << ','
		<< "non_patent_citation_num" << ','
		<< "citation_num" << ','
		<< "citation_of_domestic_num" << ','
		<< "citation_of_foreign_num" << ','
		<< "patent_type" << ','
		<< "term_of_patent_protection" << ','
		<< "classify_num" << ','
		<< "IPC_large_classify_num" << ','
		<< "IPC_sub_classify_num" << ','
		<< "kin_num" << ','
		<< "kin_of_country_num" << ','
		<< "PCT_apply" << ','
		<< "five_four_countries_patent" << ','
		<< "country_code" << ','
		<< "application_open_day_interval" << ','
		<< "application_authorization_day_interval" << ','
		<< "open_authorization_day_interval" << ','
		<< "survival_time" << ','
		<< "prority" << ','
		<< "right_num" << ','
		<< "num_of_invention" << ','
		<< "num_of_application" << ','
		<< "current_num_of_patent" << ','
		<< "type_of_application" << endl;

	for (auto&max_socre : max_complete_socre)
	{
		out_file << max_socre << ',';
	}
}

void Patent::PickCSVData()
{
	stringstream ss_stream;
	for (auto& str_line : str_vector)
	{
		shared_ptr<Patent_Data_S> temp_patent_data = make_shared<Patent_Data_S>();
		/** 0 序号 */
		int str_index = 0;

		/** 1 文献号 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->literature;
		++str_index;
		ss_stream.clear();

		/** 2 是否转让 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->transfer;
		++str_index;
		ss_stream.clear();

		/** 3 说明书页数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->instruction_num;
		++str_index;
		ss_stream.clear();

		/** 4 附图个数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->image_num;
		++str_index;
		ss_stream.clear();

		/** 5 文献引证数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->non_patent_citation_num;
		++str_index;
		ss_stream.clear();

		/** 6 专利引证数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->citation_num;
		++str_index;
		ss_stream.clear();

		/** 7 引证本国专利数*/
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->citation_of_domestic_num;
		++str_index;
		ss_stream.clear();

		/** 8 引证外国专利数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->citation_of_foreign_num;
		++str_index;
		ss_stream.clear();

		/** 9 专利类别 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->patent_type;
		++str_index;
		ss_stream.clear();

		/** 10 保护期 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->term_of_patent_protection;
		++str_index;
		ss_stream.clear();

		/** 11 分类数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->classify_num;
		++str_index;
		ss_stream.clear();

		/** 12 IPC大类数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->IPC_large_classify_num;
		++str_index;
		ss_stream.clear();

		/** 13 IPC小类数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->IPC_sub_classify_num;
		++str_index;
		ss_stream.clear();

		/** 14 同族专利数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->kin_num;
		++str_index;
		ss_stream.clear();

		/** 15 同族布局国家、地区数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->kin_of_country_num;
		++str_index;
		ss_stream.clear();

		/** 16 是否为PCT申请 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->PCT_apply;
		++str_index;
		ss_stream.clear();

		/** 17 是否为五国专利/四方专利 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->five_four_countries_patent;
		++str_index;
		ss_stream.clear();

		/** 18 专利国别代码 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->country_code;
		++str_index;
		ss_stream.clear();

		/** 19 申请日公开日时间间隔（年）*/
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->application_open_day_interval;
		++str_index;
		ss_stream.clear();

		/** 20 申请日授权日时间间隔 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->application_authorization_day_interval;
		++str_index;
		ss_stream.clear();

		/** 21 公开日授权日时间间隔 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->open_authorization_day_interval;
		++str_index;
		ss_stream.clear();

		/** 22 剩余有效期 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->survival_time;
		++str_index;
		ss_stream.clear();

		/** 23 是否有优先权 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->prority;
		++str_index;
		ss_stream.clear();

		/** 24 权项数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->right_num;
		++str_index;
		ss_stream.clear();

		/** 25 发明人数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->num_of_invention;
		++str_index;
		ss_stream.clear();

		/** 26 申请人数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->num_of_application;
		++str_index;
		ss_stream.clear();

		/** 27 当前专利权人数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->current_num_of_patent;
		++str_index;
		ss_stream.clear();

		/** 28 申请人类型 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_patent_data->type_of_application;
		++str_index;
		ss_stream.clear();

		patent_all_data.push_back(temp_patent_data);
	}
}

void Patent::PickEveStruct()
{

	for (auto& patent_data : patent_all_data)
	{
		/** 说明书页数 */
		shared_ptr<Instruction_Num> temp_instruction_num = make_shared<Instruction_Num>();
		temp_instruction_num->literature = patent_data->literature;
		temp_instruction_num->transfer = patent_data->transfer;
		temp_instruction_num->instruction_num = patent_data->instruction_num;

		/** 附图个数 */
		shared_ptr<Image_Num> temp_image_num = make_shared<Image_Num>();
		temp_image_num->literature = patent_data->literature;
		temp_image_num->transfer = patent_data->transfer;
		temp_image_num->image_num = patent_data->image_num;

		/** 文献引证数 */
		shared_ptr<Non_Patent_Citation_Num> temp_non_patent_citation_num = make_shared<Non_Patent_Citation_Num>();
		temp_non_patent_citation_num->literature = patent_data->literature;
		temp_non_patent_citation_num->transfer = patent_data->transfer;
		temp_non_patent_citation_num->non_patent_citation_num = patent_data->non_patent_citation_num;

		/** 专利引证数 */
		shared_ptr<Citation_Num> temp_citation_num = make_shared<Citation_Num>();
		temp_citation_num->literature = patent_data->literature;
		temp_citation_num->transfer = patent_data->transfer;
		temp_citation_num->citation_num = patent_data->citation_num;

		/** 引证本国专利数*/
		shared_ptr<Citation_Of_Domestic_Num> temp_citation_of_domestic_num = make_shared<Citation_Of_Domestic_Num>();
		temp_citation_of_domestic_num->literature = patent_data->literature;
		temp_citation_of_domestic_num->transfer = patent_data->transfer;
		temp_citation_of_domestic_num->citation_of_domestic_num = patent_data->citation_of_domestic_num;

		/** 引证外国专利数 */
		shared_ptr<Citation_Of_Foreign_Num> temp_citation_of_foreign_num = make_shared<Citation_Of_Foreign_Num>();
		temp_citation_of_foreign_num->literature = patent_data->literature;
		temp_citation_of_foreign_num->transfer = patent_data->transfer;
		temp_citation_of_foreign_num->citation_of_foreign_num = patent_data->citation_of_foreign_num;

		/** 专利类别 */
		shared_ptr<Patent_Type> temp_patent_type = make_shared<Patent_Type>();
		temp_patent_type->literature = patent_data->literature;
		temp_patent_type->transfer = patent_data->transfer;
		temp_patent_type->patent_type = patent_data->patent_type;

		/** 保护期 */
		shared_ptr<Term_Of_Patent_Protection> temp_term_of_patent_protection = make_shared<Term_Of_Patent_Protection>();
		temp_term_of_patent_protection->literature = patent_data->literature;
		temp_term_of_patent_protection->transfer = patent_data->transfer;
		temp_term_of_patent_protection->term_of_patent_protection = patent_data->term_of_patent_protection;

		/** 分类数 */
		shared_ptr<Classify_Num> temp_classify_num = make_shared<Classify_Num>();
		temp_classify_num->literature = patent_data->literature;
		temp_classify_num->transfer = patent_data->transfer;
		temp_classify_num->classify_num = patent_data->classify_num;

		/** IPC大类数 */
		shared_ptr<IPC_Large_Classify_Num> temp_IPC_large_classify_num = make_shared<IPC_Large_Classify_Num>();
		temp_IPC_large_classify_num->literature = patent_data->literature;
		temp_IPC_large_classify_num->transfer = patent_data->transfer;
		temp_IPC_large_classify_num->IPC_large_classify_num = patent_data->IPC_large_classify_num;

		/** IPC小类数 */
		shared_ptr<IPC_Sub_Classify_Num> temp_IPC_sub_classify_num = make_shared<IPC_Sub_Classify_Num>();
		temp_IPC_sub_classify_num->literature = patent_data->literature;
		temp_IPC_sub_classify_num->transfer = patent_data->transfer;
		temp_IPC_sub_classify_num->IPC_sub_classify_num = patent_data->IPC_sub_classify_num;

		/** 同族专利数 */
		shared_ptr<Kin_Num> temp_kin_num = make_shared<Kin_Num>();
		temp_kin_num->literature = patent_data->literature;
		temp_kin_num->transfer = patent_data->transfer;
		temp_kin_num->kin_num = patent_data->kin_num;

		/** 同族布局国家、地区数 */
		shared_ptr<Kin_Of_Country_Num> temp_kin_of_country_num = make_shared<Kin_Of_Country_Num>();
		temp_kin_of_country_num->literature = patent_data->literature;
		temp_kin_of_country_num->transfer = patent_data->transfer;
		temp_kin_of_country_num->kin_of_country_num = patent_data->kin_of_country_num;

		/** 是否为PCT申请 */
		shared_ptr<PCT_Apply> temp_PCT_apply = make_shared<PCT_Apply>();
		temp_PCT_apply->literature = patent_data->literature;
		temp_PCT_apply->transfer = patent_data->transfer;
		temp_PCT_apply->PCT_apply = patent_data->PCT_apply;

		/** 是否为五国专利/四方专利 */
		shared_ptr<Five_Four_Countries_Patent> temp_five_four_countries_patent = make_shared<Five_Four_Countries_Patent>();
		temp_five_four_countries_patent->literature = patent_data->literature;
		temp_five_four_countries_patent->transfer = patent_data->transfer;
		temp_five_four_countries_patent->five_four_countries_patent = patent_data->five_four_countries_patent;

		/** 专利国别代码 */
		shared_ptr<Country_code> temp_country_code = make_shared<Country_code>();
		temp_country_code->literature = patent_data->literature;
		temp_country_code->transfer = patent_data->transfer;
		temp_country_code->country_code = patent_data->country_code;

		/** 申请日公开日时间间隔（年）*/
		shared_ptr<Application_Open_Day_Interval> temp_application_open_day_interval = make_shared<Application_Open_Day_Interval>();
		temp_application_open_day_interval->literature = patent_data->literature;
		temp_application_open_day_interval->transfer = patent_data->transfer;
		temp_application_open_day_interval->application_open_day_interval = patent_data->application_open_day_interval;

		/** 申请日授权日时间间隔 */
		shared_ptr<Application_Authorization_Day_Interval> temp_application_authorization_day_interval = make_shared<Application_Authorization_Day_Interval>();
		temp_application_authorization_day_interval->literature = patent_data->literature;
		temp_application_authorization_day_interval->transfer = patent_data->transfer;
		temp_application_authorization_day_interval->application_authorization_day_interval = patent_data->application_authorization_day_interval;

		/** 公开日授权日时间间隔 */
		shared_ptr<Open_Authorization_Day_Interval> temp_open_authorization_day_interval = make_shared<Open_Authorization_Day_Interval>();
		temp_open_authorization_day_interval->literature = patent_data->literature;
		temp_open_authorization_day_interval->transfer = patent_data->transfer;
		temp_open_authorization_day_interval->open_authorization_day_interval = patent_data->open_authorization_day_interval;

		/** 剩余有效期 */
		shared_ptr<Survival_Time> temp_survival_time = make_shared<Survival_Time>();
		temp_survival_time->literature = patent_data->literature;
		temp_survival_time->transfer = patent_data->transfer;
		temp_survival_time->survival_time = patent_data->survival_time;

		/** 是否有优先权 */
		shared_ptr<PRORITY> temp_prority = make_shared<PRORITY>();
		temp_prority->literature = patent_data->literature;
		temp_prority->transfer = patent_data->transfer;
		temp_prority->prority = patent_data->prority;

		/** 权项数 */
		shared_ptr<Right_Num> temp_right_num = make_shared<Right_Num>();
		temp_right_num->literature = patent_data->literature;
		temp_right_num->transfer = patent_data->transfer;
		temp_right_num->right_num = patent_data->right_num;

		/** 发明人数 */
		shared_ptr<Num_Of_Invention> temp_num_of_invention = make_shared<Num_Of_Invention>();
		temp_num_of_invention->literature = patent_data->literature;
		temp_num_of_invention->transfer = patent_data->transfer;
		temp_num_of_invention->num_of_invention = patent_data->num_of_invention;

		/** 申请人数 */
		shared_ptr<Num_Of_Application> temp_num_of_application = make_shared<Num_Of_Application>();
		temp_num_of_application->literature = patent_data->literature;
		temp_num_of_application->transfer = patent_data->transfer;
		temp_num_of_application->num_of_application = patent_data->num_of_application;

		/** 当前专利权人数 */
		shared_ptr<Current_Num_Of_Patent> temp_current_num_of_patent = make_shared<Current_Num_Of_Patent>();
		temp_current_num_of_patent->literature = patent_data->literature;
		temp_current_num_of_patent->transfer = patent_data->transfer;
		temp_current_num_of_patent->current_num_of_patent = patent_data->current_num_of_patent;

		/** 申请人类型 */
		shared_ptr<Type_Of_Application> temp_type_of_application = make_shared<Type_Of_Application>();
		temp_type_of_application->literature = patent_data->literature;
		temp_type_of_application->transfer = patent_data->transfer;
		temp_type_of_application->type_of_application = patent_data->type_of_application;





		/** 说明书页数 */
		vector_instruction_num.push_back(temp_instruction_num);

		/** 附图个数 */
		vector_image_num.push_back(temp_image_num);

		/** 文献引证数 */
		vector_non_patent_citation_num.push_back(temp_non_patent_citation_num);

		/** 专利引证数 */
		vector_citation_num.push_back(temp_citation_num);

		/** 引证本国专利数*/
		vector_citation_of_domestic_num.push_back(temp_citation_of_domestic_num);

		/** 引证外国专利数 */
		vector_citation_of_foreign_num.push_back(temp_citation_of_foreign_num);

		/** 专利类别 */
		vector_patent_type.push_back(temp_patent_type);

		/** 保护期 */
		vector_term_of_patent_protection.push_back(temp_term_of_patent_protection);

		/** 分类数 */
		vector_classify_num.push_back(temp_classify_num);

		/** IPC大类数 */
		vector_IPC_large_classify_num.push_back(temp_IPC_large_classify_num);

		/** IPC小类数 */
		vector_IPC_sub_classify_num.push_back(temp_IPC_sub_classify_num);

		/** 同族专利数 */
		vector_kin_num.push_back(temp_kin_num);

		/** 同族布局国家、地区数 */
		vector_kin_of_country_num.push_back(temp_kin_of_country_num);

		/** 是否为PCT申请 */
		vector_PCT_apply.push_back(temp_PCT_apply);

		/** 是否为五国专利/四方专利 */
		vector_five_four_countries_patent.push_back(temp_five_four_countries_patent);

		/** 专利国别代码 */
		vector_country_code.push_back(temp_country_code);

		/** 申请日公开日时间间隔（年）*/
		vector_application_open_day_interval.push_back(temp_application_open_day_interval);

		/** 申请日授权日时间间隔 */
		vector_application_authorization_day_interval.push_back(temp_application_authorization_day_interval);

		/** 公开日授权日时间间隔 */
		vector_open_authorization_day_interval.push_back(temp_open_authorization_day_interval);

		/** 剩余有效期 */
		vector_survival_time.push_back(temp_survival_time);

		/** 是否有优先权 */
		vector_prority.push_back(temp_prority);

		/** 权项数 */
		vector_right_num.push_back(temp_right_num);

		/** 发明人数 */
		vector_num_of_invention.push_back(temp_num_of_invention);

		/** 申请人数 */
		vector_num_of_application.push_back(temp_num_of_application);

		/** 当前专利权人数 */
		vector_current_num_of_patent.push_back(temp_current_num_of_patent);

		/** 申请人类型 */
		vector_type_of_application.push_back(temp_type_of_application);
	}
}

void Patent::SortForEveVector()
{
	for (int i = 0; i < patent_all_data.size() - 1; ++i)
	{
		for (int j = 0; j < patent_all_data.size() - i - 1; ++j)
		{

			/** 说明书页数 */
			if (vector_instruction_num[j]->instruction_num < vector_instruction_num[j + 1]->instruction_num)
			{
				swap(vector_instruction_num[j], vector_instruction_num[j + 1]);
			}

			/** 附图个数 */
			if (vector_image_num[j]->image_num > vector_image_num[j + 1]->image_num)
			{
				swap(vector_image_num[j], vector_image_num[j + 1]);
			}

			/** 文献引证数 */
			if (vector_non_patent_citation_num[j]->non_patent_citation_num > vector_non_patent_citation_num[j + 1]->non_patent_citation_num)
			{
				swap(vector_non_patent_citation_num[j], vector_non_patent_citation_num[j + 1]);
			}

			/** 专利引证数 */
			if (vector_citation_num[j]->citation_num > vector_citation_num[j + 1]->citation_num)
			{
				swap(vector_citation_num[j], vector_citation_num[j + 1]);
			}

			/** 引证本国专利数*/
			if (vector_citation_of_domestic_num[j]->citation_of_domestic_num > vector_citation_of_domestic_num[j + 1]->citation_of_domestic_num)
			{
				swap(vector_citation_of_domestic_num[j], vector_citation_of_domestic_num[j + 1]);
			}

			/** 引证外国专利数 */
			if (vector_citation_of_foreign_num[j]->citation_of_foreign_num > vector_citation_of_foreign_num[j + 1]->citation_of_foreign_num)
			{
				swap(vector_citation_of_foreign_num[j], vector_citation_of_foreign_num[j + 1]);
			}

			/** 专利类别 */
			if (vector_patent_type[j]->patent_type > vector_patent_type[j + 1]->patent_type)
			{
				swap(vector_patent_type[j], vector_patent_type[j + 1]);
			}

			/** 保护期 */
			if (vector_term_of_patent_protection[j]->term_of_patent_protection > vector_term_of_patent_protection[j + 1]->term_of_patent_protection)
			{
				swap(vector_term_of_patent_protection[j], vector_term_of_patent_protection[j + 1]);
			}
			vector_term_of_patent_protection;

			/** 分类数 */
			if (vector_classify_num[j]->classify_num > vector_classify_num[j + 1]->classify_num)
			{
				swap(vector_classify_num[j], vector_classify_num[j + 1]);
			}

			/** IPC大类数 */
			if (vector_IPC_large_classify_num[j]->IPC_large_classify_num > vector_IPC_large_classify_num[j + 1]->IPC_large_classify_num)
			{
				swap(vector_IPC_large_classify_num[j], vector_IPC_large_classify_num[j + 1]);
			}

			/** IPC小类数 */
			if (vector_IPC_sub_classify_num[j]->IPC_sub_classify_num > vector_IPC_sub_classify_num[j + 1]->IPC_sub_classify_num)
			{
				swap(vector_IPC_sub_classify_num[j], vector_IPC_sub_classify_num[j + 1]);
			}

			/** 同族专利数 */
			if (vector_kin_num[j]->kin_num > vector_kin_num[j + 1]->kin_num)
			{
				swap(vector_kin_num[j], vector_kin_num[j + 1]);
			}

			/** 同族布局国家、地区数 */
			if (vector_kin_of_country_num[j]->kin_of_country_num > vector_kin_of_country_num[j + 1]->kin_of_country_num)
			{
				swap(vector_kin_of_country_num[j], vector_kin_of_country_num[j + 1]);
			}

			/** 是否为PCT申请 */
			if (vector_PCT_apply[j]->PCT_apply > vector_PCT_apply[j + 1]->PCT_apply)
			{
				swap(vector_PCT_apply[j], vector_PCT_apply[j + 1]);
			}

			/** 是否为五国专利/四方专利 */
			if (vector_five_four_countries_patent[j]->five_four_countries_patent > vector_five_four_countries_patent[j + 1]->five_four_countries_patent)
			{
				swap(vector_five_four_countries_patent[j], vector_five_four_countries_patent[j + 1]);
			}

			/** 专利国别代码 */
			if (vector_country_code[j]->country_code > vector_country_code[j + 1]->country_code)
			{
				swap(vector_country_code[j], vector_country_code[j + 1]);
			}

			/** 申请日公开日时间间隔（年）*/
			if (vector_application_open_day_interval[j]->application_open_day_interval > vector_application_open_day_interval[j + 1]->application_open_day_interval)
			{
				swap(vector_application_open_day_interval[j], vector_application_open_day_interval[j + 1]);
			}

			/** 申请日授权日时间间隔 */
			if (vector_application_authorization_day_interval[j]->application_authorization_day_interval > vector_application_authorization_day_interval[j + 1]->application_authorization_day_interval)
			{
				swap(vector_application_authorization_day_interval[j], vector_application_authorization_day_interval[j + 1]);
			}

			/** 公开日授权日时间间隔 */
			if (vector_open_authorization_day_interval[j]->open_authorization_day_interval > vector_open_authorization_day_interval[j + 1]->open_authorization_day_interval)
			{
				swap(vector_open_authorization_day_interval[j], vector_open_authorization_day_interval[j + 1]);
			}

			/** 剩余有效期 */
			if (vector_survival_time[j]->survival_time > vector_survival_time[j + 1]->survival_time)
			{
				swap(vector_survival_time[j], vector_survival_time[j + 1]);
			}

			/** 是否有优先权 */
			if (vector_prority[j]->prority > vector_prority[j + 1]->prority)
			{
				swap(vector_prority[j], vector_prority[j + 1]);
			}

			/** 权项数 */
			if (vector_right_num[j]->right_num > vector_right_num[j + 1]->right_num)
			{
				swap(vector_right_num[j], vector_right_num[j + 1]);
			}

			/** 发明人数 */
			if (vector_num_of_invention[j]->num_of_invention > vector_num_of_invention[j + 1]->num_of_invention)
			{
				swap(vector_num_of_invention[j], vector_num_of_invention[j + 1]);
			}

			/** 申请人数 */
			if (vector_num_of_application[j]->num_of_application > vector_num_of_application[j + 1]->num_of_application)
			{
				swap(vector_num_of_application[j], vector_num_of_application[j + 1]);
			}

			/** 当前专利权人数 */
			if (vector_current_num_of_patent[j]->current_num_of_patent > vector_current_num_of_patent[j + 1]->current_num_of_patent)
			{
				swap(vector_current_num_of_patent[j], vector_current_num_of_patent[j + 1]);
			}

			/** 申请人类型 */
			if (vector_type_of_application[j]->type_of_application > vector_type_of_application[j + 1]->type_of_application)
			{
				swap(vector_type_of_application[j], vector_type_of_application[j + 1]);
			}
		}
	}
}

void Patent::TransferOfAccumulation()
{
	/**----------------------------- 说明书页数 ------------------------------*/
	/** 转让次数，为转让次数 */
	double transfer_add_index = 0.0;
	double untransfer_add_index = 0.0;
	double temp_num = temp_num_init;
	instruction_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;

	for (auto& instruction : vector_instruction_num)
	{
		/** 同一专利群 */
		if (temp_num == instruction->instruction_num)
		{
			/** 如果转让 */
			if (instruction->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (instruction->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			instruction_num_transfer->transfer_add_index.push_back(transfer_add_index);
			instruction_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (instruction->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (instruction->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = instruction->instruction_num;
		}
	}

	/** 最后一次的 */
	instruction_num_transfer->transfer_add_index.push_back(transfer_add_index);
	instruction_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	instruction_num_transfer->transfer_num = double(transfer_add_index);
	instruction_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 附图个数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	image_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_image_num[0]->image_num;

	for (auto& image : vector_image_num)
	{
		/** 同一专利群 */
		if (temp_num == image->image_num)
		{
			/** 如果转让 */
			if (image->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (image->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			image_num_transfer->transfer_add_index.push_back(transfer_add_index);
			image_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (image->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (image->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = image->image_num;
		}
	}

	/** 最后一次的 */
	image_num_transfer->transfer_add_index.push_back(transfer_add_index);
	image_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	image_num_transfer->transfer_num = double(transfer_add_index);
	image_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 文献引证数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	non_patent_citation_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;

	/** 计算累加次数 */
	for (auto& num_data : vector_non_patent_citation_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->non_patent_citation_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			non_patent_citation_num_transfer->transfer_add_index.push_back(transfer_add_index);
			non_patent_citation_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->non_patent_citation_num;
		}
	}

	/** 最后一次的 */
	non_patent_citation_num_transfer->transfer_add_index.push_back(transfer_add_index);
	non_patent_citation_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	non_patent_citation_num_transfer->transfer_num = double(transfer_add_index);
	non_patent_citation_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 专利引证数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	citation_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;

	/** 计算累加次数 */
	for (auto& num_data : vector_citation_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->citation_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			citation_num_transfer->transfer_add_index.push_back(transfer_add_index);
			citation_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->citation_num;
		}
	}

	/** 最后一次的 */
	citation_num_transfer->transfer_add_index.push_back(transfer_add_index);
	citation_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	citation_num_transfer->transfer_num = double(transfer_add_index);
	citation_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 引证本国专利数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	citation_of_domestic_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_citation_of_domestic_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->citation_of_domestic_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			citation_of_domestic_num_transfer->transfer_add_index.push_back(transfer_add_index);
			citation_of_domestic_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->citation_of_domestic_num;
		}
	}

	/** 最后一次的 */
	citation_of_domestic_num_transfer->transfer_add_index.push_back(transfer_add_index);
	citation_of_domestic_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	citation_of_domestic_num_transfer->transfer_num = double(transfer_add_index);
	citation_of_domestic_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 引证外国专利数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	citation_of_foreign_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_citation_of_foreign_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->citation_of_foreign_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			citation_of_foreign_num_transfer->transfer_add_index.push_back(transfer_add_index);
			citation_of_foreign_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->citation_of_foreign_num;
		}
	}

	/** 最后一次的 */
	citation_of_foreign_num_transfer->transfer_add_index.push_back(transfer_add_index);
	citation_of_foreign_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	citation_of_foreign_num_transfer->transfer_num = double(transfer_add_index);
	citation_of_foreign_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 专利类别 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	patent_type_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_patent_type)
	{
		/** 同一专利群 */
		if (temp_num == num_data->patent_type)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			patent_type_transfer->transfer_add_index.push_back(transfer_add_index);
			patent_type_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->patent_type;
		}
	}

	/** 最后一次的 */
	patent_type_transfer->transfer_add_index.push_back(transfer_add_index);
	patent_type_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	patent_type_transfer->transfer_num = double(transfer_add_index);
	patent_type_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 保护期 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	term_of_patent_protection_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_term_of_patent_protection)
	{
		/** 同一专利群 */
		if (temp_num == num_data->term_of_patent_protection)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			term_of_patent_protection_transfer->transfer_add_index.push_back(transfer_add_index);
			term_of_patent_protection_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->term_of_patent_protection;
		}
	}

	/** 最后一次的 */
	term_of_patent_protection_transfer->transfer_add_index.push_back(transfer_add_index);
	term_of_patent_protection_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	term_of_patent_protection_transfer->transfer_num = double(transfer_add_index);
	term_of_patent_protection_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 分类数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	classify_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_classify_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->classify_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			classify_num_transfer->transfer_add_index.push_back(transfer_add_index);
			classify_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->classify_num;
		}
	}

	/** 最后一次的 */
	classify_num_transfer->transfer_add_index.push_back(transfer_add_index);
	classify_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	classify_num_transfer->transfer_num = double(transfer_add_index);
	classify_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ IPC大类数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	IPC_large_classify_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_IPC_large_classify_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->IPC_large_classify_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			IPC_large_classify_num_transfer->transfer_add_index.push_back(transfer_add_index);
			IPC_large_classify_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->IPC_large_classify_num;
		}
	}

	/** 最后一次的 */
	IPC_large_classify_num_transfer->transfer_add_index.push_back(transfer_add_index);
	IPC_large_classify_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	IPC_large_classify_num_transfer->transfer_num = double(transfer_add_index);
	IPC_large_classify_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ IPC小类数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	IPC_sub_classify_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_IPC_sub_classify_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->IPC_sub_classify_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			IPC_sub_classify_num_transfer->transfer_add_index.push_back(transfer_add_index);
			IPC_sub_classify_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->IPC_sub_classify_num;
		}
	}

	/** 最后一次的 */
	IPC_sub_classify_num_transfer->transfer_add_index.push_back(transfer_add_index);
	IPC_sub_classify_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	IPC_sub_classify_num_transfer->transfer_num = double(transfer_add_index);
	IPC_sub_classify_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 同族专利数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	kin_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_kin_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->kin_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			kin_num_transfer->transfer_add_index.push_back(transfer_add_index);
			kin_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->kin_num;
		}
	}

	/** 最后一次的 */
	kin_num_transfer->transfer_add_index.push_back(transfer_add_index);
	kin_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	kin_num_transfer->transfer_num = double(transfer_add_index);
	kin_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 同族布局国家、地区数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	kin_of_country_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_kin_of_country_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->kin_of_country_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			kin_of_country_num_transfer->transfer_add_index.push_back(transfer_add_index);
			kin_of_country_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->kin_of_country_num;
		}
	}

	/** 最后一次的 */
	kin_of_country_num_transfer->transfer_add_index.push_back(transfer_add_index);
	kin_of_country_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	kin_of_country_num_transfer->transfer_num = double(transfer_add_index);
	kin_of_country_num_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 是否为PCT申请 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	PCT_apply_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_PCT_apply)
	{
		/** 同一专利群 */
		if (temp_num == num_data->PCT_apply)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			PCT_apply_transfer->transfer_add_index.push_back(transfer_add_index);
			PCT_apply_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->PCT_apply;
		}
	}

	/** 最后一次的 */
	PCT_apply_transfer->transfer_add_index.push_back(transfer_add_index);
	PCT_apply_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	PCT_apply_transfer->transfer_num = double(transfer_add_index);
	PCT_apply_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 是否为五国专利/四方专利 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	five_four_countries_patent_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_five_four_countries_patent)
	{
		/** 同一专利群 */
		if (temp_num == num_data->five_four_countries_patent)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			five_four_countries_patent_transfer->transfer_add_index.push_back(transfer_add_index);
			five_four_countries_patent_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->five_four_countries_patent;
		}
	}

	/** 最后一次的 */
	five_four_countries_patent_transfer->transfer_add_index.push_back(transfer_add_index);
	five_four_countries_patent_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	five_four_countries_patent_transfer->transfer_num = double(transfer_add_index);
	five_four_countries_patent_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 专利国别代码 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	country_code_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_country_code)
	{
		/** 同一专利群 */
		if (temp_num == num_data->country_code)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			country_code_transfer->transfer_add_index.push_back(transfer_add_index);
			country_code_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->country_code;
		}
	}

	/** 最后一次的 */
	country_code_transfer->transfer_add_index.push_back(transfer_add_index);
	country_code_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	country_code_transfer->transfer_num = double(transfer_add_index);
	country_code_transfer->untransfer_num = double(untransfer_add_index);

	/**------------------------------ 申请日公开日时间间隔（年）------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	application_open_day_interval_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_application_open_day_interval)
	{
		/** 同一专利群 */
		if (temp_num == num_data->application_open_day_interval)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			application_open_day_interval_transfer->transfer_add_index.push_back(transfer_add_index);
			application_open_day_interval_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->application_open_day_interval;
		}
	}

	/** 最后一次的 */
	application_open_day_interval_transfer->transfer_add_index.push_back(transfer_add_index);
	application_open_day_interval_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	application_open_day_interval_transfer->transfer_num = double(transfer_add_index);
	application_open_day_interval_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 申请日授权日时间间隔 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	application_authorization_day_interval_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_application_authorization_day_interval)
	{
		/** 同一专利群 */
		if (temp_num == num_data->application_authorization_day_interval)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			application_authorization_day_interval_transfer->transfer_add_index.push_back(transfer_add_index);
			application_authorization_day_interval_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->application_authorization_day_interval;
		}
	}

	/** 最后一次的 */
	application_authorization_day_interval_transfer->transfer_add_index.push_back(transfer_add_index);
	application_authorization_day_interval_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	application_authorization_day_interval_transfer->transfer_num = double(transfer_add_index);
	application_authorization_day_interval_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 公开日授权日时间间隔 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	open_authorization_day_interval_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_open_authorization_day_interval)
	{
		/** 同一专利群 */
		if (temp_num == num_data->open_authorization_day_interval)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			open_authorization_day_interval_transfer->transfer_add_index.push_back(transfer_add_index);
			open_authorization_day_interval_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->open_authorization_day_interval;
		}
	}

	/** 最后一次的 */
	open_authorization_day_interval_transfer->transfer_add_index.push_back(transfer_add_index);
	open_authorization_day_interval_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	open_authorization_day_interval_transfer->transfer_num = double(transfer_add_index);
	open_authorization_day_interval_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 剩余有效期 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	survival_time_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_survival_time)
	{
		/** 同一专利群 */
		if (temp_num == num_data->survival_time)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			survival_time_transfer->transfer_add_index.push_back(transfer_add_index);
			survival_time_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->survival_time;
		}
	}

	/** 最后一次的 */
	survival_time_transfer->transfer_add_index.push_back(transfer_add_index);
	survival_time_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	survival_time_transfer->transfer_num = double(transfer_add_index);
	survival_time_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 是否有优先权 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	prority_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_prority)
	{
		/** 同一专利群 */
		if (temp_num == num_data->prority)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			prority_transfer->transfer_add_index.push_back(transfer_add_index);
			prority_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->prority;
		}
	}

	/** 最后一次的 */
	prority_transfer->transfer_add_index.push_back(transfer_add_index);
	prority_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	prority_transfer->transfer_num = double(transfer_add_index);
	prority_transfer->untransfer_num = double(untransfer_add_index);

	/**------------------------------ 权项数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	right_num_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_right_num)
	{
		/** 同一专利群 */
		if (temp_num == num_data->right_num)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			right_num_transfer->transfer_add_index.push_back(transfer_add_index);
			right_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->right_num;
		}
	}

	/** 最后一次的 */
	right_num_transfer->transfer_add_index.push_back(transfer_add_index);
	right_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	right_num_transfer->transfer_num = double(transfer_add_index);
	right_num_transfer->untransfer_num = double(untransfer_add_index);

	/**------------------------------ 发明人数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	temp_num = vector_instruction_num[0]->instruction_num;
	num_of_invention_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_num_of_invention)
	{
		/** 同一专利群 */
		if (temp_num == num_data->num_of_invention)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			num_of_invention_transfer->transfer_add_index.push_back(transfer_add_index);
			num_of_invention_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->num_of_invention;
		}
	}

	/** 最后一次的 */
	num_of_invention_transfer->transfer_add_index.push_back(transfer_add_index);
	num_of_invention_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	num_of_invention_transfer->transfer_num = double(transfer_add_index);
	num_of_invention_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 申请人数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = 1000;
	num_of_application_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_num_of_application)
	{
		/** 同一专利群 */
		if (temp_num == num_data->num_of_application)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			num_of_application_transfer->transfer_add_index.push_back(transfer_add_index);
			num_of_application_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->num_of_application;
		}
	}

	/** 最后一次的 */
	num_of_application_transfer->transfer_add_index.push_back(transfer_add_index);
	num_of_application_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	num_of_application_transfer->transfer_num = double(transfer_add_index);
	num_of_application_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 当前专利权人数 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	current_num_of_patent_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto&num_data : vector_current_num_of_patent)
	{
		/** 同一专利群 */
		if (temp_num == num_data->current_num_of_patent)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			current_num_of_patent_transfer->transfer_add_index.push_back(transfer_add_index);
			current_num_of_patent_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->current_num_of_patent;
		}
	}
	/** 最后一次的 */
	current_num_of_patent_transfer->transfer_add_index.push_back(transfer_add_index);
	current_num_of_patent_transfer->untransfer_add_index.push_back(untransfer_add_index);

	/** 总共的专利转让和为转让次数 */
	current_num_of_patent_transfer->transfer_num = double(transfer_add_index);
	current_num_of_patent_transfer->untransfer_num = double(untransfer_add_index);


	/**------------------------------ 申请人类型 ------------------------------*/
	/** 重新初始化 */
	transfer_add_index = 0.0;
	untransfer_add_index = 0.0;
	temp_num = temp_num_init;
	type_of_application_transfer = make_shared<Transfer_Data>();
	temp_num = vector_instruction_num[0]->instruction_num;
	/** 计算累加次数 */
	for (auto& num_data : vector_type_of_application)
	{
		/** 同一专利群 */
		if (temp_num == num_data->type_of_application)
		{
			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			type_of_application_transfer->transfer_add_index.push_back(transfer_add_index);
			type_of_application_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (num_data->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (num_data->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = num_data->type_of_application;
		}
	}
	/** 最后一次的 */
	type_of_application_transfer->transfer_add_index.push_back(transfer_add_index);
	type_of_application_transfer->untransfer_add_index.push_back(untransfer_add_index);

	/** 总共的专利转让和为转让次数 */
	type_of_application_transfer->transfer_num = double(transfer_add_index);
	type_of_application_transfer->untransfer_num = double(untransfer_add_index);
}

void Patent::AddTransferStruct()
{
	/** 说明书页数 */
	transfer_all_data.push_back(instruction_num_transfer);

	/** 附图个数 */
	transfer_all_data.push_back(image_num_transfer);

	/** 文献引证数 */
	transfer_all_data.push_back(non_patent_citation_num_transfer);

	/** 专利引证数 */
	transfer_all_data.push_back(citation_num_transfer);

	/** 引证本国专利数*/
	transfer_all_data.push_back(citation_of_domestic_num_transfer);

	/** 引证外国专利数 */
	transfer_all_data.push_back(citation_of_foreign_num_transfer);

	/** 专利类别 */
	transfer_all_data.push_back(patent_type_transfer);

	/** 保护期 */
	transfer_all_data.push_back(term_of_patent_protection_transfer);

	/** 分类数 */
	transfer_all_data.push_back(classify_num_transfer);

	/** IPC大类数 */
	transfer_all_data.push_back(IPC_large_classify_num_transfer);

	/** IPC小类数 */
	transfer_all_data.push_back(IPC_sub_classify_num_transfer);

	/** 同族专利数 */
	transfer_all_data.push_back(kin_num_transfer);

	/** 同族布局国家、地区数 */
	transfer_all_data.push_back(kin_of_country_num_transfer);

	/** 是否为PCT申请 */
	transfer_all_data.push_back(PCT_apply_transfer);

	/** 是否为五国专利/四方专利 */
	transfer_all_data.push_back(five_four_countries_patent_transfer);

	/** 专利国别代码 */
	transfer_all_data.push_back(country_code_transfer);

	/** 申请日公开日时间间隔（年）*/
	transfer_all_data.push_back(application_open_day_interval_transfer);

	/** 申请日授权日时间间隔 */
	transfer_all_data.push_back(application_authorization_day_interval_transfer);

	/** 公开日授权日时间间隔 */
	transfer_all_data.push_back(open_authorization_day_interval_transfer);

	/** 剩余有效期 */
	transfer_all_data.push_back(survival_time_transfer);

	/** 是否有优先权 */
	transfer_all_data.push_back(prority_transfer);

	/** 权项数 */
	transfer_all_data.push_back(right_num_transfer);

	/** 发明人数 */
	transfer_all_data.push_back(num_of_invention_transfer);

	/** 申请人数 */
	transfer_all_data.push_back(num_of_application_transfer);

	/** 当前专利权人数 */
	transfer_all_data.push_back(current_num_of_patent_transfer);

	/** 申请人类型 */
	transfer_all_data.push_back(type_of_application_transfer);
}

void Patent::CalculateDifference()
{
	/** 最大差值 */
	double temp_transfer_difference = 0.0;

	/** 每一项指标 */
	for (auto& transfer_type_data : transfer_all_data)
	{
		for (int i = 0; i < transfer_type_data->transfer_add_index.size(); i++)
		{
			double transfer_difference = transfer_type_data->transfer_add_index[i] / transfer_type_data->transfer_num
				- transfer_type_data->untransfer_add_index[i] / transfer_type_data->untransfer_num;
			double abs_transfer_difference = fabs(transfer_difference);
			if (temp_transfer_difference < abs_transfer_difference)
			{
				temp_transfer_difference = abs_transfer_difference;
			}
		}

		/** 求的最大差值 */
		transfer_type_data->first_max_d = temp_transfer_difference;

		/** 重新初始化 */
		temp_transfer_difference = 0.0;
	}
}

vector<double> Patent::GetFirestMaxDIndex()
{
	for (auto& transfer_data : transfer_all_data)
	{
		max_complete_socre.push_back(transfer_data->first_max_d);
	}
	return max_complete_socre;
}

