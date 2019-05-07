#include "patent.h"

Patent::Patent()
	:end_ok(true)
{

}

void Patent::ReadCSV()
{
	/** 打开文件 */

	ifstream in_file("E:\\development\\patent\\patentok.csv", ios::in);
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

void Patent::WriteJson()
{
	/** 写文件 */
	Json::StreamWriterBuilder stream_w_builder;
	shared_ptr<Json::StreamWriter> stream_writer(stream_w_builder.newStreamWriter());

	ofstream out_file;
	out_file.open("patent.json");
	stream_writer->write(json_root, &out_file);
	out_file.close();
	//ofstream out_file;
	//out_file.open("patent1.json");
	//out_file << json_root.toStyledString();
	//out_file.close();
/*
	ofstream os;

	os.open("PersonalInfo");

	os << sw.write(root);

	os.close();

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
*/

}

void Patent::ManageD()
{
	/** 处理数据，结构体写入 */
	PickCSVData();

	/** 写入各自的结构体 */
	PickEveStruct();

	/** 枚举转换 */
	EnumToString();

	/** 排序 */
	SortForEveVector();

	/** 累加EVE */
	TransferOfAccumulation();

	/** 计算差值D值 */
	CalculateDifference();
}

void Patent::ManageR()
{
	/** 计算各项指标的均值 */
	CalculateAverage();

	/** 计算R值 */
	CalculateRValue();

	/** 筛选R值 */
	SelectRvalue();
}

void Patent::ManageIndex()
{
	while (end_ok)
	{
		/** 计算W */
		CalculateIndexForW();

		/** 循环处理除掉1个指标后的Z值计算数据结构 */
		CalculateZFifter();

		/** 判断 */
		LeftoverIndex();
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
		double temp_double = 0.0;
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_instruction_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 4 附图个数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_image_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 5 文献引证数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_non_patent_citation_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 6 专利引证数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_citation_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 7 引证本国专利数*/
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_citation_of_domestic_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 8 引证外国专利数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_citation_of_foreign_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 9 专利类别 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_patent_type, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 10 保护期 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_term_of_patent_protection, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 11 分类数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_classify_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 12 IPC大类数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_IPC_large_classify_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 13 IPC小类数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_IPC_sub_classify_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 14 同族专利数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_kin_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 15 同族布局国家、地区数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_kin_of_country_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 16 是否为PCT申请 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_PCT_apply, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 17 是否为五国专利/四方专利 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_five_four_countries_patent, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 18 专利国别代码 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_country_code, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 19 申请日公开日时间间隔（年）*/
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_application_open_day_interval, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 20 申请日授权日时间间隔 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_application_authorization_day_interval, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 21 公开日授权日时间间隔 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_open_authorization_day_interval, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 22 剩余有效期 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_survival_time, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 23 是否有优先权 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_prority, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 24 权项数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_right_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 25 发明人数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_num_of_invention, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 26 申请人数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_num_of_application, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 27 当前专利权人数 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_current_num_of_patent, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 28 申请人类型 */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->all_patent_data_S_num.insert(make_pair(Enum_Patent::E_type_of_application, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		patent_all_data.push_back(temp_patent_data);
	}
}

void Patent::PickEveStruct()
{
	AddEnumPatent();
	for (auto& enum_patent : all_enum_patent)
	{
		/** 说明书页数 */
		vector<shared_ptr<Base_Struct>> vector_enum_num;
		for (auto& patent_data : patent_all_data)
		{
			shared_ptr<Base_Struct> temp_enum_num = make_shared<Base_Struct>();
			temp_enum_num->literature = patent_data->literature;
			temp_enum_num->transfer = patent_data->transfer;
			temp_enum_num->num_of_feature = patent_data->all_patent_data_S_num[enum_patent];
			/** 说明书页数 */
			vector_enum_num.push_back(temp_enum_num);
		}
		vector_base_struct_num.insert(make_pair(enum_patent, vector_enum_num));
		vector_enum_num.clear();
	}
}

void Patent::EnumToString()
{
	enum_to_string.insert(make_pair(E_instruction_num, "instruction_num"));
	enum_to_string.insert(make_pair(E_image_num, "image_num"));
	enum_to_string.insert(make_pair(E_non_patent_citation_num, "non_patent_citation_num"));
	enum_to_string.insert(make_pair(E_citation_num, "citation_num"));
	enum_to_string.insert(make_pair(E_citation_of_domestic_num, "citation_of_domestic_num"));
	enum_to_string.insert(make_pair(E_citation_of_foreign_num, "citation_of_foreign_num"));
	enum_to_string.insert(make_pair(E_patent_type, "patent_type"));
	enum_to_string.insert(make_pair(E_term_of_patent_protection, "term_of_patent_protection"));
	enum_to_string.insert(make_pair(E_classify_num, "classify_num"));
	enum_to_string.insert(make_pair(E_IPC_large_classify_num, "IPC_large_classify_num"));
	enum_to_string.insert(make_pair(E_IPC_sub_classify_num, "IPC_sub_classify_num"));
	enum_to_string.insert(make_pair(E_kin_num, "kin_num"));
	enum_to_string.insert(make_pair(E_kin_of_country_num, "kin_of_country_num"));
	enum_to_string.insert(make_pair(E_PCT_apply, "PCT_apply"));
	enum_to_string.insert(make_pair(E_five_four_countries_patent, "five_four_countries_patent"));
	enum_to_string.insert(make_pair(E_country_code, "country_code"));
	enum_to_string.insert(make_pair(E_application_open_day_interval, "application_open_day_interval"));
	enum_to_string.insert(make_pair(E_application_authorization_day_interval, "application_authorization_day_interval"));
	enum_to_string.insert(make_pair(E_open_authorization_day_interval, "open_authorization_day_interval"));
	enum_to_string.insert(make_pair(E_survival_time, "survival_time"));
	enum_to_string.insert(make_pair(E_prority, "prority"));
	enum_to_string.insert(make_pair(E_right_num, "right_num"));
	enum_to_string.insert(make_pair(E_num_of_invention, "num_of_invention"));
	enum_to_string.insert(make_pair(E_num_of_application, "num_of_application"));
	enum_to_string.insert(make_pair(E_current_num_of_patent, "current_num_of_patent"));
	enum_to_string.insert(make_pair(E_type_of_application, "type_of_application"));

}

void Patent::SortForEveVector()
{
	for (auto& vector_base_struct : vector_base_struct_num)
	{
		for (int i = 0; i < patent_all_data.size() - 1; ++i)
		{
			for (int j = 0; j < patent_all_data.size() - i - 1; ++j)
			{
				if (vector_base_struct.second[j]->num_of_feature < vector_base_struct.second[j + 1]->num_of_feature)
				{
					swap(vector_base_struct.second[j]->num_of_feature, vector_base_struct.second[j + 1]->num_of_feature);
				}
			}
		}
	}
}

void Patent::TransferOfAccumulation()
{
	for (auto& vector_base_struct : vector_base_struct_num)
	{
		/** 转让次数，为转让次数 */
		double transfer_add_index = 0.0;
		double untransfer_add_index = 0.0;
		double temp_num = temp_num_init;
		shared_ptr<Transfer_Data> instruction_num_transfer = make_shared<Transfer_Data>();
		temp_num = vector_base_struct.second[0]->num_of_feature;

		for (auto& instruction : vector_base_struct.second)
		{
			/** 同一专利群 */
			if (temp_num == instruction->num_of_feature)
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

				temp_num = instruction->num_of_feature;
			}
		}

		/** 最后一次的 */
		instruction_num_transfer->transfer_add_index.push_back(transfer_add_index);
		instruction_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
		/** 总共的专利转让和为转让次数 */
		instruction_num_transfer->transfer_num = double(transfer_add_index);
		instruction_num_transfer->untransfer_num = double(untransfer_add_index);
		transfer_all_data.insert(make_pair(vector_base_struct.first, instruction_num_transfer));
	}
}

void Patent::CalculateDifference()
{
	/** 最大差值 */
	double temp_transfer_difference = 0.0;
	Json::Value Difference_json;
	/** 每一项指标 */
	for (auto& transfer_type_data : transfer_all_data)
	{
		for (int i = 0; i < transfer_type_data.second->transfer_add_index.size(); i++)
		{
			double transfer_difference = transfer_type_data.second->transfer_add_index[i] / transfer_type_data.second->transfer_num
				- transfer_type_data.second->untransfer_add_index[i] / transfer_type_data.second->untransfer_num;
			double abs_transfer_difference = fabs(transfer_difference);
			if (temp_transfer_difference < abs_transfer_difference)
			{
				temp_transfer_difference = abs_transfer_difference;
			}
		}

		/** 求的最大差值 */
		transfer_type_data.second->first_max_d = temp_transfer_difference;
		Difference_json[enum_to_string[transfer_type_data.first]] = temp_transfer_difference;

		/** 重新初始化 */
		temp_transfer_difference = 0.0;
	}

	json_root["Difference"] = Difference_json;
}

void Patent::CalculateAverage()
{
	double temp_total = 0.0f;
	for (auto& vector_base_struct : vector_base_struct_num)
	{
		for (auto& instruction_num : vector_base_struct.second)
		{
			temp_total += instruction_num->num_of_feature;
		}
		temp_total /= vector_base_struct.second.size();
		R_average.insert(make_pair(vector_base_struct.first, temp_total));
		temp_total = 0.0f;
	}
}

void Patent::CalculateRValue()
{
	/**------------- 技术类 ---------*/
	/** 说明书页数  附图个数 */
	CalculateRValueM(E_instruction_num, E_image_num, R_value_Technology);
	/** 说明书页数  文献引证数 */
	CalculateRValueM(E_instruction_num, E_non_patent_citation_num, R_value_Technology);
	/** 说明书页数  专利引证数 */
	CalculateRValueM(E_instruction_num, E_citation_num, R_value_Technology);
	/** 说明书页数  引证本国专利数 */
	CalculateRValueM(E_instruction_num, E_citation_of_domestic_num, R_value_Technology);
	/** 说明书页数  引证外国专利数 */
	CalculateRValueM(E_instruction_num, E_citation_of_foreign_num, R_value_Technology);
	/** 附图个数  文献引证数 */
	CalculateRValueM(E_image_num, E_non_patent_citation_num, R_value_Technology);
	/** 附图个数  专利引证数 */
	CalculateRValueM(E_image_num, E_citation_num, R_value_Technology);
	/** 附图个数  引证本国专利数 */
	CalculateRValueM(E_image_num, E_citation_of_domestic_num, R_value_Technology);
	/** 附图个数  引证外国专利数 */
	CalculateRValueM(E_image_num, E_citation_of_foreign_num, R_value_Technology);
	/** 文献引证数  专利引证数 */
	CalculateRValueM(E_non_patent_citation_num, E_citation_num, R_value_Technology);
	/** 文献引证数  引证本国专利数 */
	CalculateRValueM(E_non_patent_citation_num, E_citation_of_domestic_num, R_value_Technology);
	/** 文献引证数  引证外国专利数 */
	CalculateRValueM(E_non_patent_citation_num, E_citation_of_foreign_num, R_value_Technology);
	/** 专利引证数  引证本国专利数 */
	CalculateRValueM(E_citation_num, E_citation_of_domestic_num, R_value_Technology);
	/** 专利引证数  引证外国专利数 */
	CalculateRValueM(E_citation_num, E_citation_of_foreign_num, R_value_Technology);
	/** 引证本国专利数  引证外国专利数 */
	CalculateRValueM(E_citation_of_domestic_num, E_citation_of_foreign_num, R_value_Technology);

	/**------------ IPC类 -------------------*/
	/** 专利类别  保护期 */
	CalculateRValueM(E_patent_type, E_term_of_patent_protection, R_value_IPC);
	/** 专利类别  分类数 */
	CalculateRValueM(E_patent_type, E_classify_num, R_value_IPC);
	/** 专利类别  IPC大类数 */
	CalculateRValueM(E_patent_type, E_IPC_large_classify_num, R_value_IPC);
	/** 专利类别  IPC小类数 */
	CalculateRValueM(E_patent_type, E_IPC_sub_classify_num, R_value_IPC);
	/** 专利类别  同族专利数 */
	CalculateRValueM(E_patent_type, E_kin_num, R_value_IPC);

	/** 保护期  分类数 */
	CalculateRValueM(E_term_of_patent_protection, E_classify_num, R_value_IPC);
	/** 保护期  IPC大类数 */
	CalculateRValueM(E_term_of_patent_protection, E_IPC_large_classify_num, R_value_IPC);
	/** 保护期  IPC小类数  */
	CalculateRValueM(E_term_of_patent_protection, E_IPC_sub_classify_num, R_value_IPC);
	/** 保护期  同族专利数 */
	CalculateRValueM(E_term_of_patent_protection, E_kin_num, R_value_IPC);

	/** 分类数  IPC大类数 */
	CalculateRValueM(E_classify_num, E_IPC_large_classify_num, R_value_IPC);
	/** 分类数  IPC小类数 */
	CalculateRValueM(E_classify_num, E_IPC_sub_classify_num, R_value_IPC);
	/** 分类数  同族专利数 */
	CalculateRValueM(E_classify_num, E_kin_num, R_value_IPC);
	/**  IPC大类数   IPC小类数  */
	CalculateRValueM(E_IPC_large_classify_num, E_IPC_sub_classify_num, R_value_IPC);
	/**  IPC大类数  同族专利数 */
	CalculateRValueM(E_IPC_large_classify_num, E_kin_num, R_value_IPC);
	/**  IPC小类数   同族专利数  */
	CalculateRValueM(E_IPC_sub_classify_num, E_kin_num, R_value_IPC);

	/**------------ 国际化 -------------------*/
	/** 同族布局国家、地区数 是否为PCT申请 */
	CalculateRValueM(E_kin_of_country_num, E_PCT_apply, R_value_Internationalization);
	/** 同族布局国家、地区数 是否为五国专利/四方专利 */
	CalculateRValueM(E_kin_of_country_num, E_five_four_countries_patent, R_value_Internationalization);
	/** 同族布局国家、地区数 专利国别代码 */
	CalculateRValueM(E_kin_of_country_num, E_country_code, R_value_Internationalization);
	/** 是否为PCT申请 是否为五国专利/四方专利 */
	CalculateRValueM(E_PCT_apply, E_five_four_countries_patent, R_value_Internationalization);
	/** 是否为PCT申请 是否为PCT申请 */
	CalculateRValueM(E_PCT_apply, E_country_code, R_value_Internationalization);
	/** 是否为五国专利/四方专利 专利国别代码 */
	CalculateRValueM(E_five_four_countries_patent, E_country_code, R_value_Internationalization);


	/**------------ 时间 -------------------*/
	/** 申请日公开日时间间隔（年）  申请日授权日时间间隔 */
	CalculateRValueM(E_application_open_day_interval, E_application_authorization_day_interval, R_value_Time);
	/** 申请日公开日时间间隔（年）  公开日授权日时间间隔 */
	CalculateRValueM(E_application_open_day_interval, E_open_authorization_day_interval, R_value_Time);
	/** 申请日公开日时间间隔（年）  剩余有效期 */
	CalculateRValueM(E_application_open_day_interval, E_survival_time, R_value_Time);
	/** 申请日授权日时间间隔  公开日授权日时间间隔 */
	CalculateRValueM(E_application_authorization_day_interval, E_open_authorization_day_interval, R_value_Time);
	/** 申请日授权日时间间隔  剩余有效期 */
	CalculateRValueM(E_application_authorization_day_interval, E_survival_time, R_value_Time);
	/** 公开日授权日时间间隔  剩余有效期 */
	CalculateRValueM(E_open_authorization_day_interval, E_survival_time, R_value_Time);

	/**------------ 权利类 -------------------*/
	/** 是否有优先权  权项数 */
	CalculateRValueM(E_prority, E_right_num, R_value_Right);

	/**------------ 发明人 申请人 -------------------*/
	/** 发明人数  申请人数 */
	CalculateRValueM(E_num_of_invention, E_num_of_application, R_value_Inventor);
	/** 发明人数  专利权人规模 */
	CalculateRValueM(E_num_of_invention, E_current_num_of_patent, R_value_Inventor);
	/** 发明人数  申请人类型 */
	CalculateRValueM(E_num_of_invention, E_type_of_application, R_value_Inventor);
	/** 申请人数  专利权人规模 */
	CalculateRValueM(E_num_of_application, E_current_num_of_patent, R_value_Inventor);
	/** 申请人数  申请人类型 */
	CalculateRValueM(E_num_of_application, E_type_of_application, R_value_Inventor);
	/** 专利权人规模  申请人类型 */
	CalculateRValueM(E_current_num_of_patent, E_type_of_application, R_value_Inventor);
}
void Patent::CalculateRValueM(Enum_Patent in_enum_first, Enum_Patent in_enum_second, vector<RValueCL>& in_R_value)
{
	double molecule = 0.0f;
	double denominator_first = 0.0f;
	double denominator_second = 0.0f;
	RValueCL temp_r_valueCL;

	for (int i = 0; i < vector_base_struct_num[in_enum_first].size(); ++i)
	{
		double first_value = vector_base_struct_num[in_enum_first][i]->num_of_feature - R_average[in_enum_first];
		double second_value = vector_base_struct_num[in_enum_second][i]->num_of_feature - R_average[in_enum_second];

		molecule += first_value * second_value;
		denominator_first += pow(first_value, 2);
		denominator_second += pow(second_value, 2);
	}

	temp_r_valueCL.first_value = in_enum_first;
	temp_r_valueCL.second_value = in_enum_second;
	temp_r_valueCL.r_value = molecule / sqrt(denominator_first * denominator_second);
	in_R_value.push_back(temp_r_valueCL);
}

void Patent::SelectRvalueM(vector<RValueCL>& in_R_value)
{
	for (auto& temp_r_value : in_R_value)
	{
		if (temp_r_value.r_value > 0.7f)
		{
			Enum_Patent temp_enum_patent = (transfer_all_data[temp_r_value.first_value]->first_max_d > transfer_all_data[temp_r_value.second_value]->first_max_d) ? temp_r_value.first_value : temp_r_value.second_value;
			selected_enum_patent.push_back(temp_enum_patent);
		}
	}
}

void Patent::AddEnumPatent()
{
	for (int i = 2; i < 28; ++i)
	{
		all_enum_patent.push_back(static_cast<Enum_Patent>(i));
	}
}

void Patent::SelectRafterD()
{
	Json::Value RafterD;
	/** 总的transfer结构体数据 */
	for (auto& temp_select_num : selected_enum_patent)
	{
		RafterD.append(enum_to_string[temp_select_num]);
		transfer_after_data.insert(make_pair(temp_select_num, transfer_all_data[temp_select_num]));
	}
	json_root["r_after_d_index"] = RafterD;
}

void Patent::SelectRvalue()
{
	SelectRvalueM(R_value_Technology);
	SelectRvalueM(R_value_IPC);
	SelectRvalueM(R_value_Internationalization);
	SelectRvalueM(R_value_Time);
	SelectRvalueM(R_value_Right);
	SelectRvalueM(R_value_Inventor);

	/** 去重 */
	set<Enum_Patent> temp_set(selected_enum_patent.begin(), selected_enum_patent.end());
	selected_enum_patent.assign(temp_set.begin(), temp_set.end());

	vector<Enum_Patent>::iterator temp_iter;

	vector<Enum_Patent> temp_all_enum_patent = all_enum_patent;
	for (auto& temp_selected_enum : selected_enum_patent)
	{
		for (temp_iter = temp_all_enum_patent.begin(); temp_iter != temp_all_enum_patent.end();)
		{
			if (*temp_iter == temp_selected_enum)
			{
				pass_selected_enum_patent.push_back(temp_selected_enum);
				temp_iter = temp_all_enum_patent.erase(temp_iter);
			}
			else
			{
				++temp_iter;
			}
		}
	}
	selected_enum_patent.clear();
	selected_enum_patent = temp_all_enum_patent;
	SelectRafterD();
}


void Patent::CalculateWValueFull(map<Enum_Patent, double>& in_w_data_fifter_for_z)
{
	in_w_data_fifter_for_z.clear();
	double D_total = 0.0;
	for (auto& temp_transfer_after : transfer_after_data)
	{
		D_total += temp_transfer_after.second->first_max_d;
	}

	for (auto& temp_transfer_after : transfer_after_data)
	{
		double temp_w_once = temp_transfer_after.second->first_max_d / D_total;
		in_w_data_fifter_for_z.insert(make_pair(temp_transfer_after.first, temp_w_once));
	}
}

void Patent::CalculateWValueDelete(map<Enum_Patent, map<Enum_Patent, double>>& in_w_data_fifter_for_all)
{
	in_w_data_fifter_for_all.clear();
	for (auto& selected_num_once : selected_enum_patent)
	{
		double D_total = 0.0;
		map<Enum_Patent, double> w_data_once;
		for (auto& temp_transfer_after_once : transfer_after_data)
		{
			if (selected_num_once != temp_transfer_after_once.first)
			{
				D_total += temp_transfer_after_once.second->first_max_d;
			}
		}

		for (auto& temp_transfer_after_second : transfer_after_data)
		{
			if (selected_num_once != temp_transfer_after_second.first)
			{
				double temp_w_once = temp_transfer_after_second.second->first_max_d / D_total;
				w_data_once.insert(make_pair(temp_transfer_after_second.first, temp_w_once));
			}
		}
		in_w_data_fifter_for_all.insert(make_pair(selected_num_once, w_data_once));
	}
}

void Patent::CalculateZValueFull(vector<Enum_Patent>& in_selected_enum_patent, vector<shared_ptr<Base_Struct>>& in_Z_fifter_full_vector, map<Enum_Patent, double>& in_w_data_fifter_for_z)
{
	in_Z_fifter_full_vector.clear();
	for (auto& temp_patent_data : patent_all_data)
	{
		shared_ptr<Base_Struct> temp_once_patent_Z = make_shared<Base_Struct>();
		for (auto& temp_once_enum_patent : in_selected_enum_patent)
		{
			temp_once_patent_Z->num_of_feature += temp_patent_data->all_patent_data_S_num[temp_once_enum_patent] * in_w_data_fifter_for_z[temp_once_enum_patent];
		}
		temp_once_patent_Z->literature = temp_patent_data->literature;
		temp_once_patent_Z->transfer = temp_patent_data->transfer;
		temp_once_patent_Z->num_of_feature *= 100.0;
		in_Z_fifter_full_vector.push_back(temp_once_patent_Z);
	}

	/** 降序排列Z值 */
	for (int i = 0; i < in_Z_fifter_full_vector.size() - 1; ++i)
	{
		for (int j = 0; j < in_Z_fifter_full_vector.size() - i - 1; ++j)
		{
			if (in_Z_fifter_full_vector[j]->num_of_feature < in_Z_fifter_full_vector[j + 1]->num_of_feature)
			{
				swap(in_Z_fifter_full_vector[j], in_Z_fifter_full_vector[j + 1]);
			}
		}
	}
}

void Patent::CalculateZValueDelete(vector<Enum_Patent>& in_selected_enum_patent, map<Enum_Patent, vector<shared_ptr<Base_Struct>>>& in_Z_fifter_delete_vector, map<Enum_Patent, map<Enum_Patent, double>>& in_w_data_fifter_for_all)
{
	in_Z_fifter_delete_vector.clear();
	for (auto& w_data_fifter_once : in_w_data_fifter_for_all)
	{
		vector<shared_ptr<Base_Struct>> temp_Z_total_vector;
		for (auto& temp_patent_data : patent_all_data)
		{
			shared_ptr<Base_Struct> temp_once_patent_Z = make_shared<Base_Struct>();
			for (auto& temp_once_enum_patent : in_selected_enum_patent)
			{
				if (temp_once_enum_patent != w_data_fifter_once.first)
				{
					temp_once_patent_Z->num_of_feature += temp_patent_data->all_patent_data_S_num[temp_once_enum_patent] * w_data_fifter_once.second[temp_once_enum_patent];
				}
			}
			temp_once_patent_Z->literature = temp_patent_data->literature;
			temp_once_patent_Z->transfer = temp_patent_data->transfer;
			temp_once_patent_Z->num_of_feature *= 100.0;
			temp_Z_total_vector.push_back(temp_once_patent_Z);
		}

		/** 降序排列Z值 */
		for (int i = 0; i < temp_Z_total_vector.size() - 1; ++i)
		{
			for (int j = 0; j < temp_Z_total_vector.size() - i - 1; ++j)
			{
				if (temp_Z_total_vector[j]->num_of_feature < temp_Z_total_vector[j + 1]->num_of_feature)
				{
					swap(temp_Z_total_vector[j], temp_Z_total_vector[j + 1]);
				}
			}
		}
		in_Z_fifter_delete_vector.insert(make_pair(w_data_fifter_once.first, temp_Z_total_vector));
	}
}

void Patent::CalculateZtotalDFull(vector<shared_ptr<Base_Struct>>& in_Z_fifter_full_vector, shared_ptr<Transfer_Data>& in_Z_fifter_full_transfer)
{
	/** 转让次数，为转让次数 */
	double transfer_add_index = 0.0;
	double untransfer_add_index = 0.0;
	double temp_num = temp_num_init;
	temp_num = in_Z_fifter_full_vector[0]->num_of_feature;
	in_Z_fifter_full_transfer = make_shared<Transfer_Data>();
	for (auto& temp_z_total : in_Z_fifter_full_vector)
	{
		/** 同一专利群 */
		if (temp_num == temp_z_total->num_of_feature)
		{
			/** 如果转让 */
			if (temp_z_total->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (temp_z_total->transfer == 0)
			{
				++untransfer_add_index;
			}
			continue;
		}
		/** 不同专利群 */
		else
		{
			in_Z_fifter_full_transfer->transfer_add_index.push_back(transfer_add_index);
			in_Z_fifter_full_transfer->untransfer_add_index.push_back(untransfer_add_index);

			/** 如果转让 */
			if (temp_z_total->transfer == 1)
			{
				++transfer_add_index;
			}
			/** 如果未转让 */
			if (temp_z_total->transfer == 0)
			{
				++untransfer_add_index;
			}

			temp_num = temp_z_total->num_of_feature;
		}
	}

	/** 最后一次的 */
	in_Z_fifter_full_transfer->transfer_add_index.push_back(transfer_add_index);
	in_Z_fifter_full_transfer->untransfer_add_index.push_back(untransfer_add_index);
	/** 总共的专利转让和为转让次数 */
	in_Z_fifter_full_transfer->transfer_num = double(transfer_add_index);
	in_Z_fifter_full_transfer->untransfer_num = double(untransfer_add_index);

	/** 最大差值 */
	double temp_transfer_difference = 0.0;

	/** 每一项指标 */
	for (int i = 0; i < in_Z_fifter_full_transfer->transfer_add_index.size(); i++)
	{
		double transfer_difference = in_Z_fifter_full_transfer->transfer_add_index[i] / in_Z_fifter_full_transfer->transfer_num
			- in_Z_fifter_full_transfer->untransfer_add_index[i] / in_Z_fifter_full_transfer->untransfer_num;
		double abs_transfer_difference = fabs(transfer_difference);
		if (temp_transfer_difference < abs_transfer_difference)
		{
			temp_transfer_difference = abs_transfer_difference;
		}
	}

	/** 求的最大差值 */
	in_Z_fifter_full_transfer->first_max_d = temp_transfer_difference;
}


void Patent::CalculateZtotalDDelete(map<Enum_Patent, shared_ptr<Transfer_Data>>& in_Z_fifter_delete_transfer, map<Enum_Patent, vector<shared_ptr<Base_Struct>>>& in_Z_fifter_delete_vector)
{
	in_Z_fifter_delete_transfer.clear();
	for (auto& Z_fifter_transfer_once : in_Z_fifter_delete_vector)
	{
		/** 转让次数，为转让次数 */
		double transfer_add_index = 0.0;
		double untransfer_add_index = 0.0;
		double temp_num = temp_num_init;
		temp_num = Z_fifter_transfer_once.second[0]->num_of_feature;
		shared_ptr<Transfer_Data> temp_Z_transfer = make_shared<Transfer_Data>();
		for (auto& temp_z_total : Z_fifter_transfer_once.second)
		{
			/** 同一专利群 */
			if (temp_num == temp_z_total->num_of_feature)
			{
				/** 如果转让 */
				if (temp_z_total->transfer == 1)
				{
					++transfer_add_index;
				}
				/** 如果未转让 */
				if (temp_z_total->transfer == 0)
				{
					++untransfer_add_index;
				}
				continue;
			}
			/** 不同专利群 */
			else
			{
				temp_Z_transfer->transfer_add_index.push_back(transfer_add_index);
				temp_Z_transfer->untransfer_add_index.push_back(untransfer_add_index);

				/** 如果转让 */
				if (temp_z_total->transfer == 1)
				{
					++transfer_add_index;
				}
				/** 如果未转让 */
				if (temp_z_total->transfer == 0)
				{
					++untransfer_add_index;
				}

				temp_num = temp_z_total->num_of_feature;
			}
		}

		/** 最后一次的 */
		temp_Z_transfer->transfer_add_index.push_back(transfer_add_index);
		temp_Z_transfer->untransfer_add_index.push_back(untransfer_add_index);
		/** 总共的专利转让和为转让次数 */
		temp_Z_transfer->transfer_num = double(transfer_add_index);
		temp_Z_transfer->untransfer_num = double(untransfer_add_index);

		/** 最大差值 */
		double temp_transfer_difference = 0.0;

		/** 每一项指标 */

		for (int i = 0; i < temp_Z_transfer->transfer_add_index.size(); i++)
		{
			double transfer_difference = temp_Z_transfer->transfer_add_index[i] / temp_Z_transfer->transfer_num
				- temp_Z_transfer->untransfer_add_index[i] / temp_Z_transfer->untransfer_num;
			double abs_transfer_difference = fabs(transfer_difference);
			if (temp_transfer_difference < abs_transfer_difference)
			{
				temp_transfer_difference = abs_transfer_difference;
			}
		}

		/** 求的最大差值 */
		temp_Z_transfer->first_max_d = temp_transfer_difference;
		in_Z_fifter_delete_transfer.insert(make_pair(Z_fifter_transfer_once.first, temp_Z_transfer));
	}
}

void Patent::CalculateIndexForW()
{
	/** 处理循环后的transfer */
	for (auto& temp_pass_selected_enum : pass_selected_enum_patent)
	{
		map<Enum_Patent, shared_ptr<Transfer_Data>>::iterator iter_transfer = transfer_after_data.find(temp_pass_selected_enum);
		if (iter_transfer != transfer_after_data.end())
		{
			transfer_after_data.erase(temp_pass_selected_enum);
		}
	}

	/** 筛选后的W值  用来计算没有去掉指标的Z值 */
	CalculateWValueFull(w_data_fifter_for_z);

	/** 计算所有指标 除掉后的W */
	CalculateWValueDelete(w_data_fifter_for_all);
}

void Patent::CalculateZFifter()
{
	/** 计算Z值，全指标 */
	CalculateZValueFull(selected_enum_patent, Z_fifter_full_vector, w_data_fifter_for_z);
	/** 计算去掉过指标的Z值 */
	CalculateZValueDelete(selected_enum_patent, Z_fifter_delete_vector, w_data_fifter_for_all);

	/** 计算总的Z结构体 */
	CalculateZtotalDFull(Z_fifter_full_vector, Z_fifter_full_transfer);
	/** 计算Z_total的D值，循环指标 */
	CalculateZtotalDDelete(Z_fifter_delete_transfer, Z_fifter_delete_vector);
}

void Patent::LeftoverIndex()
{
	double max_d_value = 0.0;
	Enum_Patent temp_enum_max;
	for (auto& Z_fifter_transfer_once : Z_fifter_delete_transfer)
	{
		if (Z_fifter_transfer_once.second->first_max_d > max_d_value)
		{
			max_d_value = Z_fifter_transfer_once.second->first_max_d;
			temp_enum_max = Z_fifter_transfer_once.first;
		}
	}

	bool temp_end_ok = false;
	if (max_d_value > Z_fifter_full_transfer->first_max_d)
	{
		temp_end_ok = true;
		pass_selected_enum_patent.push_back(temp_enum_max);

		vector<Enum_Patent> temp_selected_enum_patent;
		for (auto& temp_selected_next : selected_enum_patent)
		{
			if (temp_selected_next != temp_enum_max)
			{
				temp_selected_enum_patent.push_back(temp_selected_next);
			}
		}
		selected_enum_patent.clear();
		selected_enum_patent = temp_selected_enum_patent;
	}

	if (!temp_end_ok)
	{
		end_ok = temp_end_ok;
	}

	Json::Value Z_fifter_json;
	Z_fifter_json["z_max_full"] = Z_fifter_full_transfer->first_max_d;
	Z_fifter_json["z_max_delete"] = max_d_value;

	for (auto& temp_selected_to_json : selected_enum_patent)
	{
		Z_fifter_json["z_enum_after"].append(enum_to_string[temp_selected_to_json]);
	}
	json_root["z_fifter"].append(Z_fifter_json);
}
