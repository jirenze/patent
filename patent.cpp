#include "patent.h"

Patent::Patent()
{

}

void Patent::ReadCSV()
{
	/** ���ļ� */
	ifstream in_file("C:\\Users\\jiren\\Desktop\\patent18\\patentnow.csv", ios::in);
	string temp_line_str;

	/** ����ܷ�� */
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
		/** ��ɶ�ά�ṹ */
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
	/** д�ļ� */
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

	for (auto& max_socre : max_complete_socre)
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
		/** 0 ��� */
		int str_index = 0;

		/** 1 ���׺� */
		ss_stream << str_line[str_index];
		string temp_literature;
		ss_stream >> temp_literature;
		temp_patent_data->literature.insert(make_pair(E_literature, temp_literature));
		++str_index;
		ss_stream.clear();

		/** 2 �Ƿ�ת�� */
		ss_stream << str_line[str_index];
		int temp_transfer = 0;
		ss_stream >> temp_transfer;
		temp_patent_data->transfer.insert(make_pair(E_transfer, temp_transfer));
		++str_index;
		ss_stream.clear();

		/** 3 ˵����ҳ�� */
		ss_stream << str_line[str_index];
		double temp_double = 0.0;
		ss_stream >> temp_double;
		temp_patent_data->instruction_num.insert(make_pair(E_instruction_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 4 ��ͼ���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->image_num.insert(make_pair(E_image_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 5 ������֤�� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->non_patent_citation_num.insert(make_pair(E_non_patent_citation_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 6 ר����֤�� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->citation_num.insert(make_pair(E_citation_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 7 ��֤����ר����*/
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->citation_of_domestic_num.insert(make_pair(E_citation_of_domestic_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 8 ��֤���ר���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->citation_of_foreign_num.insert(make_pair(E_citation_of_foreign_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 9 ר����� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->patent_type.insert(make_pair(E_patent_type, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 10 ������ */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->term_of_patent_protection.insert(make_pair(E_term_of_patent_protection, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 11 ������ */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->classify_num.insert(make_pair(E_classify_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 12 IPC������ */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->IPC_large_classify_num.insert(make_pair(E_IPC_large_classify_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 13 IPCС���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->IPC_sub_classify_num.insert(make_pair(E_IPC_sub_classify_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 14 ͬ��ר���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->kin_num.insert(make_pair(E_kin_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 15 ͬ�岼�ֹ��ҡ������� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->kin_of_country_num.insert(make_pair(E_kin_of_country_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 16 �Ƿ�ΪPCT���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->PCT_apply.insert(make_pair(E_PCT_apply, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 17 �Ƿ�Ϊ���ר��/�ķ�ר�� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->five_four_countries_patent.insert(make_pair(E_five_four_countries_patent, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 18 ר��������� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->country_code.insert(make_pair(E_country_code, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 19 �����չ�����ʱ�������꣩*/
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->application_open_day_interval.insert(make_pair(E_application_open_day_interval, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 20 ��������Ȩ��ʱ���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->application_authorization_day_interval.insert(make_pair(E_application_authorization_day_interval, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 21 ��������Ȩ��ʱ���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->open_authorization_day_interval.insert(make_pair(E_open_authorization_day_interval, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 22 ʣ����Ч�� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->survival_time.insert(make_pair(E_survival_time, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 23 �Ƿ�������Ȩ */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->prority.insert(make_pair(E_prority, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 24 Ȩ���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->right_num.insert(make_pair(E_right_num, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 25 �������� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->num_of_invention.insert(make_pair(E_num_of_invention, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 26 �������� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->num_of_application.insert(make_pair(E_num_of_application, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 27 ��ǰר��Ȩ���� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->current_num_of_patent.insert(make_pair(E_current_num_of_patent, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		/** 28 ���������� */
		ss_stream << str_line[str_index];
		ss_stream >> temp_double;
		temp_patent_data->type_of_application.insert(make_pair(E_type_of_application, temp_double));
		++str_index;
		ss_stream.clear();
		temp_double = 0.0;

		patent_all_data.push_back(temp_patent_data);
	}
}

void Patent::PickEveStruct()
{
	/** ˵����ҳ�� */
	vector<shared_ptr<Base_Struct>> vector_instruction_num;
	/** ��ͼ���� */
	vector<shared_ptr<Base_Struct>> vector_image_num;
	/** ������֤�� */
	vector<shared_ptr<Base_Struct>> vector_non_patent_citation_num;
	/** ר����֤�� */
	vector<shared_ptr<Base_Struct>> vector_citation_num;
	/** ��֤����ר����*/
	vector<shared_ptr<Base_Struct>> vector_citation_of_domestic_num;
	/** ��֤���ר���� */
	vector<shared_ptr<Base_Struct>> vector_citation_of_foreign_num;
	/** ר����� */
	vector<shared_ptr<Base_Struct>> vector_patent_type;
	/** ������ */
	vector<shared_ptr<Base_Struct>> vector_term_of_patent_protection;
	/** ������ */
	vector<shared_ptr<Base_Struct>> vector_classify_num;
	/** IPC������ */
	vector<shared_ptr<Base_Struct>> vector_IPC_large_classify_num;
	/** IPCС���� */
	vector<shared_ptr<Base_Struct>> vector_IPC_sub_classify_num;
	/** ͬ��ר���� */
	vector<shared_ptr<Base_Struct>> vector_kin_num;
	/** ͬ�岼�ֹ��ҡ������� */
	vector<shared_ptr<Base_Struct>> vector_kin_of_country_num;
	/** �Ƿ�ΪPCT���� */
	vector<shared_ptr<Base_Struct>> vector_PCT_apply;
	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	vector<shared_ptr<Base_Struct>> vector_five_four_countries_patent;
	/** ר��������� */
	vector<shared_ptr<Base_Struct>>  vector_country_code;
	/** �����չ�����ʱ�������꣩*/
	vector<shared_ptr<Base_Struct>> vector_application_open_day_interval;
	/** ��������Ȩ��ʱ���� */
	vector<shared_ptr<Base_Struct>> vector_application_authorization_day_interval;
	/** ��������Ȩ��ʱ���� */
	vector<shared_ptr<Base_Struct>> vector_open_authorization_day_interval;
	/** ʣ����Ч�� */
	vector<shared_ptr<Base_Struct>> vector_survival_time;
	/** �Ƿ�������Ȩ */
	vector<shared_ptr<Base_Struct>> vector_prority;
	/** Ȩ���� */
	vector<shared_ptr<Base_Struct>> vector_right_num;
	/** �������� */
	vector<shared_ptr<Base_Struct>> vector_num_of_invention;
	/** �������� */
	vector<shared_ptr<Base_Struct>> vector_num_of_application;
	/** ��ǰר��Ȩ���� */
	vector<shared_ptr<Base_Struct>> vector_current_num_of_patent;
	/** ���������� */
	vector<shared_ptr<Base_Struct>> vector_type_of_application;

	for (auto& patent_data : patent_all_data)
	{
		/** ˵����ҳ�� */
		shared_ptr<Base_Struct> temp_instruction_num = make_shared<Base_Struct>();
		temp_instruction_num->literature = patent_data->literature;
		temp_instruction_num->transfer = patent_data->transfer;
		temp_instruction_num->num_of_feature = patent_data->instruction_num;

		/** ��ͼ���� */
		shared_ptr<Base_Struct> temp_image_num = make_shared<Base_Struct>();
		temp_image_num->literature = patent_data->literature;
		temp_image_num->transfer = patent_data->transfer;
		temp_image_num->num_of_feature = patent_data->image_num;

		/** ������֤�� */
		shared_ptr<Base_Struct> temp_non_patent_citation_num = make_shared<Base_Struct>();
		temp_non_patent_citation_num->literature = patent_data->literature;
		temp_non_patent_citation_num->transfer = patent_data->transfer;
		temp_non_patent_citation_num->num_of_feature = patent_data->non_patent_citation_num;

		/** ר����֤�� */
		shared_ptr<Base_Struct> temp_citation_num = make_shared<Base_Struct>();
		temp_citation_num->literature = patent_data->literature;
		temp_citation_num->transfer = patent_data->transfer;
		temp_citation_num->num_of_feature = patent_data->citation_num;

		/** ��֤����ר����*/
		shared_ptr<Base_Struct> temp_citation_of_domestic_num = make_shared<Base_Struct>();
		temp_citation_of_domestic_num->literature = patent_data->literature;
		temp_citation_of_domestic_num->transfer = patent_data->transfer;
		temp_citation_of_domestic_num->num_of_feature = patent_data->citation_of_domestic_num;

		/** ��֤���ר���� */
		shared_ptr<Base_Struct> temp_citation_of_foreign_num = make_shared<Base_Struct>();
		temp_citation_of_foreign_num->literature = patent_data->literature;
		temp_citation_of_foreign_num->transfer = patent_data->transfer;
		temp_citation_of_foreign_num->num_of_feature = patent_data->citation_of_foreign_num;

		/** ר����� */
		shared_ptr<Base_Struct> temp_patent_type = make_shared<Base_Struct>();
		temp_patent_type->literature = patent_data->literature;
		temp_patent_type->transfer = patent_data->transfer;
		temp_patent_type->num_of_feature = patent_data->patent_type;

		/** ������ */
		shared_ptr<Base_Struct> temp_term_of_patent_protection = make_shared<Base_Struct>();
		temp_term_of_patent_protection->literature = patent_data->literature;
		temp_term_of_patent_protection->transfer = patent_data->transfer;
		temp_term_of_patent_protection->num_of_feature = patent_data->term_of_patent_protection;

		/** ������ */
		shared_ptr<Base_Struct> temp_classify_num = make_shared<Base_Struct>();
		temp_classify_num->literature = patent_data->literature;
		temp_classify_num->transfer = patent_data->transfer;
		temp_classify_num->num_of_feature = patent_data->classify_num;

		/** IPC������ */
		shared_ptr<Base_Struct> temp_IPC_large_classify_num = make_shared<Base_Struct>();
		temp_IPC_large_classify_num->literature = patent_data->literature;
		temp_IPC_large_classify_num->transfer = patent_data->transfer;
		temp_IPC_large_classify_num->num_of_feature = patent_data->IPC_large_classify_num;

		/** IPCС���� */
		shared_ptr<Base_Struct> temp_IPC_sub_classify_num = make_shared<Base_Struct>();
		temp_IPC_sub_classify_num->literature = patent_data->literature;
		temp_IPC_sub_classify_num->transfer = patent_data->transfer;
		temp_IPC_sub_classify_num->num_of_feature = patent_data->IPC_sub_classify_num;

		/** ͬ��ר���� */
		shared_ptr<Base_Struct> temp_kin_num = make_shared<Base_Struct>();
		temp_kin_num->literature = patent_data->literature;
		temp_kin_num->transfer = patent_data->transfer;
		temp_kin_num->num_of_feature = patent_data->kin_num;

		/** ͬ�岼�ֹ��ҡ������� */
		shared_ptr<Base_Struct> temp_kin_of_country_num = make_shared<Base_Struct>();
		temp_kin_of_country_num->literature = patent_data->literature;
		temp_kin_of_country_num->transfer = patent_data->transfer;
		temp_kin_of_country_num->num_of_feature = patent_data->kin_of_country_num;

		/** �Ƿ�ΪPCT���� */
		shared_ptr<Base_Struct> temp_PCT_apply = make_shared<Base_Struct>();
		temp_PCT_apply->literature = patent_data->literature;
		temp_PCT_apply->transfer = patent_data->transfer;
		temp_PCT_apply->num_of_feature = patent_data->PCT_apply;

		/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
		shared_ptr<Base_Struct> temp_five_four_countries_patent = make_shared<Base_Struct>();
		temp_five_four_countries_patent->literature = patent_data->literature;
		temp_five_four_countries_patent->transfer = patent_data->transfer;
		temp_five_four_countries_patent->num_of_feature = patent_data->five_four_countries_patent;

		/** ר��������� */
		shared_ptr<Base_Struct> temp_country_code = make_shared<Base_Struct>();
		temp_country_code->literature = patent_data->literature;
		temp_country_code->transfer = patent_data->transfer;
		temp_country_code->num_of_feature = patent_data->country_code;

		/** �����չ�����ʱ�������꣩*/
		shared_ptr<Base_Struct> temp_application_open_day_interval = make_shared<Base_Struct>();
		temp_application_open_day_interval->literature = patent_data->literature;
		temp_application_open_day_interval->transfer = patent_data->transfer;
		temp_application_open_day_interval->num_of_feature = patent_data->application_open_day_interval;

		/** ��������Ȩ��ʱ���� */
		shared_ptr<Base_Struct> temp_application_authorization_day_interval = make_shared<Base_Struct>();
		temp_application_authorization_day_interval->literature = patent_data->literature;
		temp_application_authorization_day_interval->transfer = patent_data->transfer;
		temp_application_authorization_day_interval->num_of_feature = patent_data->application_authorization_day_interval;

		/** ��������Ȩ��ʱ���� */
		shared_ptr<Base_Struct> temp_open_authorization_day_interval = make_shared<Base_Struct>();
		temp_open_authorization_day_interval->literature = patent_data->literature;
		temp_open_authorization_day_interval->transfer = patent_data->transfer;
		temp_open_authorization_day_interval->num_of_feature = patent_data->open_authorization_day_interval;

		/** ʣ����Ч�� */
		shared_ptr<Base_Struct> temp_survival_time = make_shared<Base_Struct>();
		temp_survival_time->literature = patent_data->literature;
		temp_survival_time->transfer = patent_data->transfer;
		temp_survival_time->num_of_feature = patent_data->survival_time;

		/** �Ƿ�������Ȩ */
		shared_ptr<Base_Struct> temp_prority = make_shared<Base_Struct>();
		temp_prority->literature = patent_data->literature;
		temp_prority->transfer = patent_data->transfer;
		temp_prority->num_of_feature = patent_data->prority;

		/** Ȩ���� */
		shared_ptr<Base_Struct> temp_right_num = make_shared<Base_Struct>();
		temp_right_num->literature = patent_data->literature;
		temp_right_num->transfer = patent_data->transfer;
		temp_right_num->num_of_feature = patent_data->right_num;

		/** �������� */
		shared_ptr<Base_Struct> temp_num_of_invention = make_shared<Base_Struct>();
		temp_num_of_invention->literature = patent_data->literature;
		temp_num_of_invention->transfer = patent_data->transfer;
		temp_num_of_invention->num_of_feature = patent_data->num_of_invention;

		/** �������� */
		shared_ptr<Base_Struct> temp_num_of_application = make_shared<Base_Struct>();
		temp_num_of_application->literature = patent_data->literature;
		temp_num_of_application->transfer = patent_data->transfer;
		temp_num_of_application->num_of_feature = patent_data->num_of_application;

		/** ��ǰר��Ȩ���� */
		shared_ptr<Base_Struct> temp_current_num_of_patent = make_shared<Base_Struct>();
		temp_current_num_of_patent->literature = patent_data->literature;
		temp_current_num_of_patent->transfer = patent_data->transfer;
		temp_current_num_of_patent->num_of_feature = patent_data->current_num_of_patent;

		/** ���������� */
		shared_ptr<Base_Struct> temp_type_of_application = make_shared<Base_Struct>();
		temp_type_of_application->literature = patent_data->literature;
		temp_type_of_application->transfer = patent_data->transfer;
		temp_type_of_application->num_of_feature = patent_data->type_of_application;



		/** ˵����ҳ�� */
		vector_instruction_num.push_back(temp_instruction_num);
		/** ��ͼ���� */
		vector_image_num.push_back(temp_image_num);
		/** ������֤�� */
		vector_non_patent_citation_num.push_back(temp_non_patent_citation_num);
		/** ר����֤�� */
		vector_citation_num.push_back(temp_citation_num);
		/** ��֤����ר����*/
		vector_citation_of_domestic_num.push_back(temp_citation_of_domestic_num);
		/** ��֤���ר���� */
		vector_citation_of_foreign_num.push_back(temp_citation_of_foreign_num);
		/** ר����� */
		vector_patent_type.push_back(temp_patent_type);
		/** ������ */
		vector_term_of_patent_protection.push_back(temp_term_of_patent_protection);
		/** ������ */
		vector_classify_num.push_back(temp_classify_num);
		/** IPC������ */
		vector_IPC_large_classify_num.push_back(temp_IPC_large_classify_num);
		/** IPCС���� */
		vector_IPC_sub_classify_num.push_back(temp_IPC_sub_classify_num);
		/** ͬ��ר���� */
		vector_kin_num.push_back(temp_kin_num);
		/** ͬ�岼�ֹ��ҡ������� */
		vector_kin_of_country_num.push_back(temp_kin_of_country_num);
		/** �Ƿ�ΪPCT���� */
		vector_PCT_apply.push_back(temp_PCT_apply);
		/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
		vector_five_four_countries_patent.push_back(temp_five_four_countries_patent);
		/** ר��������� */
		vector_country_code.push_back(temp_country_code);
		/** �����չ�����ʱ�������꣩*/
		vector_application_open_day_interval.push_back(temp_application_open_day_interval);
		/** ��������Ȩ��ʱ���� */
		vector_application_authorization_day_interval.push_back(temp_application_authorization_day_interval);
		/** ��������Ȩ��ʱ���� */
		vector_open_authorization_day_interval.push_back(temp_open_authorization_day_interval);
		/** ʣ����Ч�� */
		vector_survival_time.push_back(temp_survival_time);
		/** �Ƿ�������Ȩ */
		vector_prority.push_back(temp_prority);
		/** Ȩ���� */
		vector_right_num.push_back(temp_right_num);
		/** �������� */
		vector_num_of_invention.push_back(temp_num_of_invention);
		/** �������� */
		vector_num_of_application.push_back(temp_num_of_application);
		/** ��ǰר��Ȩ���� */
		vector_current_num_of_patent.push_back(temp_current_num_of_patent);
		/** ���������� */
		vector_type_of_application.push_back(temp_type_of_application);
	}

	/** ˵����ҳ�� */
	vector_base_struct_num.insert(make_pair(E_instruction_num, vector_instruction_num));
	/** ��ͼ���� */
	vector_base_struct_num.insert(make_pair(E_image_num, vector_image_num));
	/** ������֤�� */
	vector_base_struct_num.insert(make_pair(E_non_patent_citation_num, vector_non_patent_citation_num));
	/** ר����֤�� */
	vector_base_struct_num.insert(make_pair(E_citation_num, vector_citation_num));
	/** ��֤����ר����*/
	vector_base_struct_num.insert(make_pair(E_citation_of_domestic_num, vector_citation_of_domestic_num));
	/** ��֤���ר���� */
	vector_base_struct_num.insert(make_pair(E_citation_of_foreign_num, vector_citation_of_foreign_num));
	/** ר����� */
	vector_base_struct_num.insert(make_pair(E_patent_type, vector_patent_type));
	/** ������ */
	vector_base_struct_num.insert(make_pair(E_term_of_patent_protection, vector_term_of_patent_protection));
	/** ������ */
	vector_base_struct_num.insert(make_pair(E_classify_num, vector_classify_num));
	/** IPC������ */
	vector_base_struct_num.insert(make_pair(E_IPC_large_classify_num, vector_IPC_large_classify_num));
	/** IPCС���� */
	vector_base_struct_num.insert(make_pair(E_IPC_sub_classify_num, vector_IPC_sub_classify_num));
	/** ͬ��ר���� */
	vector_base_struct_num.insert(make_pair(E_kin_num, vector_kin_num));
	/** ͬ�岼�ֹ��ҡ������� */
	vector_base_struct_num.insert(make_pair(E_kin_of_country_num, vector_kin_of_country_num));
	/** �Ƿ�ΪPCT���� */
	vector_base_struct_num.insert(make_pair(E_PCT_apply, vector_PCT_apply));
	/** �Ƿ�Ϊ���ר��/�ķ�ר�� */
	vector_base_struct_num.insert(make_pair(E_five_four_countries_patent, vector_five_four_countries_patent));
	/** ר��������� */
	vector_base_struct_num.insert(make_pair(E_country_code, vector_country_code));
	/** �����չ�����ʱ�������꣩*/
	vector_base_struct_num.insert(make_pair(E_application_open_day_interval, vector_application_open_day_interval));
	/** ��������Ȩ��ʱ���� */
	vector_base_struct_num.insert(make_pair(E_application_authorization_day_interval, vector_application_authorization_day_interval));
	/** ��������Ȩ��ʱ���� */
	vector_base_struct_num.insert(make_pair(E_open_authorization_day_interval, vector_open_authorization_day_interval));
	/** ʣ����Ч�� */
	vector_base_struct_num.insert(make_pair(E_survival_time, vector_survival_time));
	/** �Ƿ�������Ȩ */
	vector_base_struct_num.insert(make_pair(E_prority, vector_prority));
	/** Ȩ���� */
	vector_base_struct_num.insert(make_pair(E_right_num, vector_right_num));
	/** �������� */
	vector_base_struct_num.insert(make_pair(E_num_of_invention, vector_num_of_invention));
	/** �������� */
	vector_base_struct_num.insert(make_pair(E_num_of_application, vector_num_of_application));
	/** ר��Ȩ�˹�ģ */
	vector_base_struct_num.insert(make_pair(E_current_num_of_patent, vector_current_num_of_patent));
	/** ���������� */
	vector_base_struct_num.insert(make_pair(E_type_of_application, vector_type_of_application));


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
		/**----------------------------- ˵����ҳ�� ------------------------------*/
		/** ת�ô�����Ϊת�ô��� */
		double transfer_add_index = 0.0;
		double untransfer_add_index = 0.0;
		double temp_num = temp_num_init;
		shared_ptr<Transfer_Data> instruction_num_transfer = make_shared<Transfer_Data>();
		temp_num = vector_base_struct.second[0]->num_of_feature;

		for (auto& instruction : vector_base_struct.second)
		{
			/** ͬһר��Ⱥ */
			if (temp_num == instruction->num_of_feature)
			{
				/** ���ת�� */
				if (instruction->transfer == 1)
				{
					++transfer_add_index;
				}
				/** ���δת�� */
				if (instruction->transfer == 0)
				{
					++untransfer_add_index;
				}
				continue;
			}
			/** ��ͬר��Ⱥ */
			else
			{
				instruction_num_transfer->transfer_add_index.push_back(transfer_add_index);
				instruction_num_transfer->untransfer_add_index.push_back(untransfer_add_index);

				/** ���ת�� */
				if (instruction->transfer == 1)
				{
					++transfer_add_index;
				}
				/** ���δת�� */
				if (instruction->transfer == 0)
				{
					++untransfer_add_index;
				}

				temp_num = instruction->num_of_feature;
			}
		}

		/** ���һ�ε� */
		instruction_num_transfer->transfer_add_index.push_back(transfer_add_index);
		instruction_num_transfer->untransfer_add_index.push_back(untransfer_add_index);
		/** �ܹ���ר��ת�ú�Ϊת�ô��� */
		instruction_num_transfer->transfer_num = double(transfer_add_index);
		instruction_num_transfer->untransfer_num = double(untransfer_add_index);
		transfer_all_data.insert(make_pair(vector_base_struct.first, instruction_num_transfer));
	}
}

void Patent::CalculateDifference()
{
	/** ����ֵ */
	double temp_transfer_difference = 0.0;

	/** ÿһ��ָ�� */
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

		/** �������ֵ */
		transfer_type_data.second->first_max_d = temp_transfer_difference;

		/** ���³�ʼ�� */
		temp_transfer_difference = 0.0;
	}
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


vector<double> Patent::GetFirestMaxDIndex()
{
	for (auto& transfer_data : transfer_all_data)
	{
		max_complete_socre.push_back(transfer_data.second->first_max_d);
	}
	return max_complete_socre;
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
	temp_r_valueCL.r_value = molecule / (denominator_first * denominator_second);
	in_R_value.push_back(temp_r_valueCL);
}



void Patent::CalculateRValue()
{
	/**------------- ������ ---------*/
	/** ˵����ҳ��  ��ͼ���� */
	CalculateRValueM(E_instruction_num, E_image_num, R_value_Technology);
	/** ˵����ҳ��  ������֤�� */
	CalculateRValueM(E_instruction_num, E_non_patent_citation_num, R_value_Technology);
	/** ˵����ҳ��  ר����֤�� */
	CalculateRValueM(E_instruction_num, E_citation_num, R_value_Technology);
	/** ˵����ҳ��  ��֤����ר���� */
	CalculateRValueM(E_instruction_num, E_citation_of_domestic_num, R_value_Technology);
	/** ˵����ҳ��  ��֤���ר���� */
	CalculateRValueM(E_instruction_num, E_citation_of_foreign_num, R_value_Technology);
	/** ��ͼ����  ������֤�� */
	CalculateRValueM(E_image_num, E_non_patent_citation_num, R_value_Technology);
	/** ��ͼ����  ר����֤�� */
	CalculateRValueM(E_image_num, E_citation_num, R_value_Technology);
	/** ��ͼ����  ��֤����ר���� */
	CalculateRValueM(E_image_num, E_citation_of_domestic_num, R_value_Technology);
	/** ��ͼ����  ��֤���ר���� */
	CalculateRValueM(E_image_num, E_citation_of_foreign_num, R_value_Technology);
	/** ������֤��  ר����֤�� */
	CalculateRValueM(E_non_patent_citation_num, E_citation_num, R_value_Technology);
	/** ������֤��  ��֤����ר���� */
	CalculateRValueM(E_non_patent_citation_num, E_citation_of_domestic_num, R_value_Technology);
	/** ������֤��  ��֤���ר���� */
	CalculateRValueM(E_non_patent_citation_num, E_citation_of_foreign_num, R_value_Technology);
	/** ר����֤��  ��֤����ר���� */
	CalculateRValueM(E_citation_num, E_citation_of_domestic_num, R_value_Technology);
	/** ר����֤��  ��֤���ר���� */
	CalculateRValueM(E_citation_num, E_citation_of_foreign_num, R_value_Technology);
	/** ��֤����ר����  ��֤���ר���� */
	CalculateRValueM(E_citation_of_domestic_num, E_citation_of_foreign_num, R_value_Technology);

	/**------------ IPC�� -------------------*/
	/** ר�����  ������ */
	CalculateRValueM(E_patent_type, E_term_of_patent_protection, R_value_IPC);
	/** ר�����  ������ */
	CalculateRValueM(E_patent_type, E_classify_num, R_value_IPC);
	/** ר�����  IPC������ */
	CalculateRValueM(E_patent_type, E_IPC_large_classify_num, R_value_IPC);
	/** ר�����  IPCС���� */
	CalculateRValueM(E_patent_type, E_IPC_sub_classify_num, R_value_IPC);
	/** ר�����  ͬ��ר���� */
	CalculateRValueM(E_patent_type, E_kin_num, R_value_IPC);

	/** ������  ������ */
	CalculateRValueM(E_term_of_patent_protection, E_classify_num, R_value_IPC);
	/** ������  IPC������ */
	CalculateRValueM(E_term_of_patent_protection, E_IPC_large_classify_num, R_value_IPC);
	/** ������  IPCС����  */
	CalculateRValueM(E_term_of_patent_protection, E_IPC_sub_classify_num, R_value_IPC);
	/** ������  ͬ��ר���� */
	CalculateRValueM(E_term_of_patent_protection, E_kin_num, R_value_IPC);

	/** ������  IPC������ */
	CalculateRValueM(E_classify_num, E_IPC_large_classify_num, R_value_IPC);
	/** ������  IPCС���� */
	CalculateRValueM(E_classify_num, E_IPC_sub_classify_num, R_value_IPC);
	/** ������  ͬ��ר���� */
	CalculateRValueM(E_classify_num, E_kin_num, R_value_IPC);
	/**  IPC������   IPCС����  */
	CalculateRValueM(E_IPC_large_classify_num, E_IPC_sub_classify_num, R_value_IPC);
	/**  IPC������  ͬ��ר���� */
	CalculateRValueM(E_IPC_large_classify_num, E_kin_num, R_value_IPC);
	/**  IPCС����   ͬ��ר����  */
	CalculateRValueM(E_IPC_sub_classify_num, E_kin_num, R_value_IPC);

	/**------------ ���ʻ� -------------------*/
	/** ͬ�岼�ֹ��ҡ������� �Ƿ�ΪPCT���� */
	CalculateRValueM(E_kin_of_country_num, E_PCT_apply, R_value_Internationalization);
	/** ͬ�岼�ֹ��ҡ������� �Ƿ�Ϊ���ר��/�ķ�ר�� */
	CalculateRValueM(E_kin_of_country_num, E_five_four_countries_patent, R_value_Internationalization);
	/** ͬ�岼�ֹ��ҡ������� ר��������� */
	CalculateRValueM(E_kin_of_country_num, E_country_code, R_value_Internationalization);
	/** �Ƿ�ΪPCT���� �Ƿ�Ϊ���ר��/�ķ�ר�� */
	CalculateRValueM(E_PCT_apply, E_five_four_countries_patent, R_value_Internationalization);
	/** �Ƿ�ΪPCT���� �Ƿ�ΪPCT���� */
	CalculateRValueM(E_PCT_apply, E_country_code, R_value_Internationalization);
	/** �Ƿ�Ϊ���ר��/�ķ�ר�� ר��������� */
	CalculateRValueM(E_five_four_countries_patent, E_country_code, R_value_Internationalization);


	/**------------ ʱ�� -------------------*/
	/** �����չ�����ʱ�������꣩  ��������Ȩ��ʱ���� */
	CalculateRValueM(E_application_open_day_interval, E_application_authorization_day_interval, R_value_Time);
	/** �����չ�����ʱ�������꣩  ��������Ȩ��ʱ���� */
	CalculateRValueM(E_application_open_day_interval, E_open_authorization_day_interval, R_value_Time);
	/** �����չ�����ʱ�������꣩  ʣ����Ч�� */
	CalculateRValueM(E_application_open_day_interval, E_survival_time, R_value_Time);
	/** ��������Ȩ��ʱ����  ��������Ȩ��ʱ���� */
	CalculateRValueM(E_application_authorization_day_interval, E_open_authorization_day_interval, R_value_Time);
	/** ��������Ȩ��ʱ����  ʣ����Ч�� */
	CalculateRValueM(E_application_authorization_day_interval, E_survival_time, R_value_Time);
	/** ��������Ȩ��ʱ����  ʣ����Ч�� */
	CalculateRValueM(E_open_authorization_day_interval, E_survival_time, R_value_Time);

	/**------------ Ȩ���� -------------------*/
	/** �Ƿ�������Ȩ  Ȩ���� */
	CalculateRValueM(E_prority, E_right_num, R_value_Right);

	/**------------ ������ ������ -------------------*/
	/** ��������  �������� */
	CalculateRValueM(E_num_of_invention, E_num_of_application, R_value_Inventor);
	/** ��������  ר��Ȩ�˹�ģ */
	CalculateRValueM(E_num_of_invention, E_current_num_of_patent, R_value_Inventor);
	/** ��������  ���������� */
	CalculateRValueM(E_num_of_invention, E_type_of_application, R_value_Inventor);
	/** ��������  ר��Ȩ�˹�ģ */
	CalculateRValueM(E_num_of_application, E_current_num_of_patent, R_value_Inventor);
	/** ��������  ���������� */
	CalculateRValueM(E_num_of_application, E_type_of_application, R_value_Inventor);
	/** ר��Ȩ�˹�ģ  ���������� */
	CalculateRValueM(E_current_num_of_patent, E_type_of_application, R_value_Inventor);
}
void Patent::SelectRvalue()
{
	SelectRvalueM(R_value_Technology);
	SelectRvalueM(R_value_IPC);
	SelectRvalueM(R_value_Internationalization);
	SelectRvalueM(R_value_Time);
	SelectRvalueM(R_value_Right);
	SelectRvalueM(R_value_Inventor);

	/** ȥ�� */
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
}

void Patent::SelectRafterD()
{
	/** �ܵ�transfer�ṹ������ */
	for (auto& temp_select_num : selected_enum_patent)
	{
		transfer_after_data.insert(make_pair(temp_select_num, transfer_all_data[temp_select_num]));
	}
}

void Patent::CalculateWValue()
{
	double D_total = 0.0;
	for (auto& temp_transfer_after : transfer_after_data)
	{
		D_total += temp_transfer_after.second->first_max_d;
	}

	for (auto& temp_transfer_after : transfer_after_data)
	{
		double temp_w_once = temp_transfer_after.second->first_max_d / D_total;
		w_data.insert(make_pair(temp_transfer_after.first, temp_w_once));
	}
}

void Patent::CalculateZValue()
{
	for (auto& temp_base_strcut_num : vector_base_struct_num)
	{
		temp_base_strcut_num
	}


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

