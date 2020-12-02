#ifndef METERVALUE_H
#define METERVALUE_H

//---------------------------------------------------------------------------
#define ONEBYTE_0x00h L"Успешно."
#define ONEBYTE_0x01h L"Недопустимая команда или параметр."
#define ONEBYTE_0x02h L"Внутренняя ошибка счетчика."
#define ONEBYTE_0x03h L"Не достаточен уровень доступа для удовлетворения запроса."
#define ONEBYTE_0x04h L"Внутренние часы счетчика уже корректировались в течение текущих суток."
#define ONEBYTE_0x05h L"Не открыт канал связи."

#define Condition_E01 L"Напряжение батарейки ниже 2,2(В)"
#define Condition_E02 L"Нарушено функционирование памяти2"
#define Condition_E03 L"Нарушено функционирование UART"
#define Condition_E04 L"Нарушено функционирование ADS"
#define Condition_E05 L"Ошибка обмена с памятью 1"
#define Condition_E06 L"Неисправность часов"
#define Condition_E07 L"Нарушено функционирование памяти 3"
#define Condition_E09 L"Ошибка КС ПО"
#define Condition_E10 L"Ошибка калибровочных коэффициентов"
#define Condition_E11 L"Ошибка регистров накопленной энергии"
#define Condition_E12 L"Ошибка сетевого адреса"
#define Condition_E13 L"Ошибка серийного номера"
#define Condition_E14 L"Поврежден пароль"
#define Condition_E15 L"Ошибка массива вариантов исполнения"
#define Condition_E16 L"Поврежден флаг тарификатора"
#define Condition_E17 L"Поврежден флаг отключения нагрузки"
#define Condition_E18 L"Ошибка лимита мощности"
#define Condition_E19 L"Ошибка лимита энергии"
#define Condition_E20 L"Нарушение параметров UART"
#define Condition_E21 L"Ошибка параметров индикации по тарифам"
#define Condition_E22 L"Ошибка параметров индикации по периодам"
#define Condition_E23 L"Повреждение множителя таймаута"
#define Condition_E24 L"Поврежден байт программируемых флагов"
#define Condition_E25 L"Повреждено расписание праздничных дней"
#define Condition_E26 L"Повреждено тарифное расписание"
#define Condition_E27 L"Поврежден массив таймера"
#define Condition_E28 L"Ошибка сезонных переходов"
#define Condition_E29 L"Ошибка местоположения прибора"
#define Condition_E30 L"Повреждены коэффициенты трансформации"
#define Condition_E31 L"Повреждены регистры накопления"
#define Condition_E32 L"Ошибка параметров среза"
#define Condition_E33 L"Повреждены регистры среза"
#define Condition_E34 L"Ошибка указателей журнала событий"
#define Condition_E35 L"Ошибка записи журнала событий"
#define Condition_E36 L"Повреждение регистра учета технических потерь"
#define Condition_E37 L"Ошибка мощностей технических потерь"
#define Condition_E38 L"Ошибка регистров накопленной энергии потерь"
#define Condition_E39 L"Повреждены регистры пофазного учета"
#define Condition_E40 L"Флаг поступления широковещ. сообщения"
#define Condition_E41 L"Повреждение указателей журнала ПКЭ"
#define Condition_E42 L"Ошибка записи журнала ПКЭ"
#define Condition_E47 L"Выполнение процедуры коррекции времени"
#define Condition_E48 L"Напряжение батарейки ниже 2,65(В)"
#define Condition_Temperature L"Температура прибора"

#define Consist_SoftVer L"версия ПО счётчика"
#define Consist_In L"Iн Iн - номинальный ток (А)"
#define Consist_Un L"Uн Uн - номинальное напряжение (В)"
#define Consist_ClR L"Cl R класс точности по реактивной энергии (%)"
#define Consist_ClA L"Cl А класс точности по активной энергии (%)"
#define Consist_MeterConst L"Постоянная счетчика (имп./квт*ч)"
#define Consist_NPhase L"Число фаз"
#define Consist_ProfMPower L"Учет профиля средних мощностей"
#define Consist_TempRange L"Температурный диапазон (°C)"
#define Consist_NDirect L"Число направлений"
#define Consist_NVarProd_Un L"Номинальное напряжение (В)"
#define Consist_NVarProd_In L"Номинальный ток (А)"
#define Consist_NVarProd_Imax L"Максимальный ток (А)"
#define Consist_NVarProd_MConst L"Постоянная счетчика, имп./кВт*ч"
#define Consist_MeterType L"Тип счетчика"
#define Consist_Tarificator L"Тарификатор"
#define Consist_SumPhase L"Суммирование фаз"
#define Consist_EPlonb L"Эл. помба верхней крышки"
#define Consist_ExSupp L"Внешнее питание"
#define Consist_IFace L"Интерфейс"
#define Consist_OPort L"оптопорт"
#define Consist_ModemGSM L"Модем GSM"
#define Consist_ModemPLM L"Модем PLC"
#define Consist_Mem3 L"Память No3"
#define Consist_PhCalcPower L"Пофазный учет энергии A+"
#define Consist_QPower L"Контроль ПКЭ"
#define Consist_SupIF1 L"Встроенное питание интерфейса 1"
#define Consist_IFace2 L"Интерфейс 2"
#define Consist_CEPlomb L"Флаг наличия эл. пломбы защитной крышки"
#define Consist_TarMax L"Флаг потарифного учета максимумов мощности"
#define Consist_Light L"Флаг наличия подсветки ЖКИ"
#define Consist_Relay L"Флаг наличия встроенного реле"
#define Consist_ExControl L"Флаг наличия аппаратных средств управления внешними устройствами отключения нагрузки"
#define Consist_VoltTarif L"Флаг переключения тарифов внешним напряжением"
#define Consist_BEPlomb L"Флаг наличия эл.пломбы модульного отсека"
#define Consist_Profile2 L"Флаг наличия профиля 2"
#define Consist_ModemPLC2 L"Модем PLC2"
#define Consist_IEC61107 L"Флаг протокола IEC61107"
#define Consist_Kvolt L"Коэффициент трансформации по напряжению"
#define Consist_Kcurr L"Коэффициент трансформации по току"

#define ElectroVal_Voltage_Phase1 L"Напряжение фазы 1 (В)"
#define ElectroVal_Voltage_Phase2 L"Напряжение фазы 2 (В)"
#define ElectroVal_Voltage_Phase3 L"Напряжение фазы 3 (В)"
#define ElectroVal_Current_Phase1 L"Ток фазы 1 (А)"
#define ElectroVal_Current_Phase2 L"Ток фазы 2 (А)"
#define ElectroVal_Current_Phase3 L"Ток фазы 3 (А)"
#define ElectroVal_Angle_Phase1 L"угол между напряжениями фаз 1-2 (°)"
#define ElectroVal_Angle_Phase2 L"угол между напряжениями фаз 1-3 (°)"
#define ElectroVal_Angle_Phase3 L"угол между напряжениями фаз 2-3 (°)"
#define ElectroVal_PowerFactor_SumPhase L"Коэффициент мощности суммы фаз"
#define ElectroVal_PowerFactor_Phase1 L"Коэффициент мощности cosФ фазы 1"
#define ElectroVal_PowerFactor_Phase2 L"Коэффициент мощности cosФ фазы 2"
#define ElectroVal_PowerFactor_Phase3 L"Коэффициент мощности cosФ фазы 3"
#define ElectroVal_KADirect_SumPhase L"Направление активной мощности суммы фаз"
#define ElectroVal_KADirect_Phase1 L"Направление активной мощности фазы 1"
#define ElectroVal_KADirect_Phase2 L"Направление активной мощности фазы 2"
#define ElectroVal_KADirect_Phase3 L"Направление активной мощности фазы 3"
#define ElectroVal_KRDirect_SumPhase L"Направление реактивной мощности суммы фаз"
#define ElectroVal_KRDirect_Phase1 L"Направление реактивной мощности фазы 1"
#define ElectroVal_KRDirect_Phase2 L"Направление реактивной мощности фазы 2"
#define ElectroVal_KRDirect_Phase3 L"Направление реактивной мощности фазы 3"
#define ElectroVal_PPower_SumPhase L"Активная мощность P(Ватт) суммы фаз"
#define ElectroVal_PPower_Phase1 L"Активная мощность P(Ватт) фазы 1"
#define ElectroVal_PPower_Phase2 L"Активная мощность P(Ватт) фазы 2"
#define ElectroVal_PPower_Phase3 L"Активная мощность P(Ватт) фазы 3"
#define ElectroVal_PADirect_SumPhase L"Направление активной мощности суммы фаз"
#define ElectroVal_PADirect_Phase1 L"Направление активной мощности фазы 1"
#define ElectroVal_PADirect_Phase2 L"Направление активной мощности фазы 2"
#define ElectroVal_PADirect_Phase3 L"Направление активной мощности фазы 3"
#define ElectroVal_QPower_SumPhase L"Реактивная мощность Q(ВАр - Вольт Ампер реактивный) суммы фаз"
#define ElectroVal_QPower_Phase1 L"Реактивная мощность Q(ВАр - Вольт Ампер реактивный) фазы 1"
#define ElectroVal_QPower_Phase2 L"Реактивная мощность Q(ВАр - Вольт Ампер реактивный) фазы 2"
#define ElectroVal_QPower_Phase3 L"Реактивная мощность Q(ВАр - Вольт Ампер реактивный) фазы 3"
#define ElectroVal_QRDirect_SumPhase L"Направление реактивной мощности суммы фаз"
#define ElectroVal_QRDirect_Phase1 L"Направление реактивной мощности фазы 1"
#define ElectroVal_QRDirect_Phase2 L"Направление реактивной мощности фазы 2"
#define ElectroVal_QRDirect_Phase3 L"Направление реактивной мощности фазы 3"
#define ElectroVal_SPower_SumPhase L"Полная мощность S(ВА - Вольт Ампер) суммы фаз"
#define ElectroVal_SPower_Phase1 L"Полная мощность S(ВА - Вольт Ампер) фазы 1"
#define ElectroVal_SPower_Phase2 L"Полная мощность S(ВА - Вольт Ампер) фазы 2"
#define ElectroVal_SPower_Phase3 L"Полная мощность S(ВА - Вольт Ампер) фазы 3"
#define ElectroVal_SADirect_SumPhase L"Направление активной мощности суммы фаз"
#define ElectroVal_SADirect_Phase1 L"Направление активной мощности фазы 1"
#define ElectroVal_SADirect_Phase2 L"Направление активной мощности фазы 2"
#define ElectroVal_SADirect_Phase3 L"Направление активной мощности фазы 3"
#define ElectroVal_SRDirect_SumPhase L"Направление реактивной мощности суммы фаз"
#define ElectroVal_SRDirect_Phase1 L"Направление реактивной мощности фазы 1"
#define ElectroVal_SRDirect_Phase2 L"Направление реактивной мощности фазы 2"
#define ElectroVal_SRDirect_Phase3 L"Направление реактивной мощности фазы 3"
#define ElectroVal_Frequency L"Частота (Гц)"
#define ElectroVal_Distortion_Phase1 L"Коэффициент искажения синусоидальности фазного напряжения фазы 1"
#define ElectroVal_Distortion_Phase2 L"Коэффициент искажения синусоидальности фазного напряжения фазы 2"
#define ElectroVal_Distortion_Phase3 L"Коэффициент искажения синусоидальности фазного напряжения фазы 3"

#define MINMETERADDRESS 1
#define MAXMETERADDRESS 253
#define BCASTMETERADDRESS 0
//#define MINMERCURYADDRESS 0x01
//#define MAXMERCURYADDRESS 0xFD
#define MINACCESSLEVEL 1
#define MAXACCESSLEVEL 2
#define DEFAULTACCESSLEVEL "1"

#pragma pack (push, 1)
struct DEFAULTPASSWORD
{
    unsigned char	DPass1;
    unsigned char	DPass2;
    unsigned char	DPass3;
    unsigned char	DPass4;
    unsigned char	DPass5;
    unsigned char	DPass6;
};
#pragma pack (pop)
#define DEFAULTPASSWORDLEN sizeof(DEFAULTPASSWORD)
#define EXPECT_DEFAULTPASSWORDLEN 6
#define MINLEVELACCESS 0x01
#define MAXLEVELACCESS 0x02

#pragma pack (push, 1)
struct LONGLONG8BYTE
{
    unsigned char	HiByte1;
    unsigned char	Byte2;
    unsigned char	Byte3;
    unsigned char	Byte4;
    unsigned char	Byte5;
    unsigned char	Byte6;
    unsigned char	Byte7;
    unsigned char	LoByte8;
};
#pragma pack (pop)

//2.3.1 Чтение серийного номера счетчика и даты выпуска.
//В ответ на запрос счетчик возвращает 7 байт в поле данных ответа. Первые 4 байта - се-
//рийный номер в двоичном позиционном коде, следующие 3 байта - дата выпуска в 2/10-м коде
//в последовательности: число, месяц, год.
#pragma pack (push, 1)
struct METERDATA
{
    unsigned char		ZeroByte; //выравнивание к 8 байтам SN и ProdData
    unsigned char		SN1;      //  серийный
    unsigned char		SN2;      //          номер
    unsigned char		SN3;      //               прибора
    unsigned char		SN4;      //                      учета
    unsigned char		ProdDay;     //  дата
    unsigned char		ProdMonth;   //      производства
    unsigned char		ProdYear;    //                  прибора
    unsigned char		Address; // Не 0 когда прибор по этому адресу откликается на запрося
    unsigned char		Result;  // Код возвращенный последним запросом
    unsigned char		Level; //  уровень доступа обеспечивающий выполнение всех необходимых функций
    unsigned char		DisableRead; // Когда установлено - чтение прибора запрещено
    unsigned char		ZeroPass1; // Выравнивание Pass к 8 байтам
    unsigned char		ZeroPass2;
    unsigned char		Pass[DEFAULTPASSWORDLEN]; // Пароль доступа к этому прибору
    unsigned long long	MercuryID; // ID счетчика 00 SN1 SN2 SN3 SN4 ProdDay ProdMonth ProdYear
    unsigned long long	AccessPassword; // Пароль 00 00 Pass[0] Pass[1] Pass[2] Pass[3] Pass[4] Pass[5]
};
#pragma pack (pop)
#define METERDATALEN sizeof(METERDATA)

#define REQSEQUENCLEN 8
#define RESPSTRUCRLEN 256
#pragma pack (push, 1)
struct EXCHANGEMETER
{
    unsigned char   ReqSequenc[REQSEQUENCLEN];
    int    ReqSequencIdx;
    unsigned char   RespStruct[RESPSTRUCRLEN];
    int    RespStructIdx;
};
#pragma pack (pop)

struct TDateTime
{
    int    year;
    int    month;
    int    day;
    int    hour;
    int    mminute;
    int    second;
    int    msecond;
};

//время прибора
struct METERDATETIME
{
    TDateTime	Val;
    int			WeekDay;
    bool		Winter;
};

//состояние прибора
//TEMPERATURE	 	int	 		2.3.15.5 Ответ прибора на запрос чтения температуры. TEMPERATURE
//STATEWORD	 	WORDSTATE	 	2.3.11 Чтение слова состояния. STATEWORD
struct CONDITION
{
    int		Temperature; //Температура прибора
    bool	E01; //  Напряжение батарейки ниже 2,2(В)
    bool	E02; //  Нарушено функционирование памяти2
    bool	E03; //  Нарушено функционирование UART
    bool	E04; //  Нарушено функционирование ADS
    bool	E05; //  Ошибка обмена с памятью1
    bool	E06; //  Неисправность часов
    bool	E07; //  Нарушено функционирование памяти3
    bool	E09; //  Ошибка КС ПО
    bool	E10; //  Ошибка калибровочных коэффициентов
    bool	E11; //  Ошибка регистров накопленной энергии
    bool	E12; //  Ошибка сетевого адреса
    bool	E13; //  Ошибка серийного номера
    bool	E14; //  Поврежден пароль
    bool	E15; //  Ошибка массива вариантов исполнения
    bool	E16; //  Поврежден флаг тарификатора
    bool	E17; //  Поврежден флаг отключения нагрузки
    bool	E18; //  Ошибка лимита мощности
    bool	E19; //  Ошибка лимита энергии
    bool	E20; //  Нарушение параметров UART
    bool	E21; //  Ошибка параметров индикации по тарифам
    bool	E22; //  Ошибка параметров индикации по периодам
    bool	E23; //  Повреждение множителя таймаута
    bool	E24; //  Поврежден байт программируемых флагов
    bool	E25; //  Повреждено расписание праздничных дней
    bool	E26; //  Повреждено тарифное расписание
    bool	E27; //  Поврежден массив таймера
    bool	E28; //  Ошибка сезонных переходов
    bool	E29; //  Ошибка местоположения прибора
    bool	E30; //  Повреждены коэффициенты трансформации
    bool	E31; //  Повреждены регистры накопления
    bool	E32; //  Ошибка параметров среза
    bool	E33; //  Повреждены регистры среза
    bool	E34; //  Ошибка указателей журнала событий
    bool	E35; //  Ошибка записи журнала событий
    bool	E36; //  Повреждение регистра учета технических потерь
    bool	E37; //  Ошибка мощностей технических потерь
    bool	E38; //  Ошибка регистров накопленной энергии потерь
    bool	E39; //  Повреждены регистры пофазного учета
    bool	E40; //  Флаг поступления широковещ. сообщения
    bool	E41; //  Повреждение указателей журнала ПКЭ
    bool	E42; //  Ошибка записи журнала ПКЭ
    bool	E47; //  Выполнение процедуры коррекции времени
    bool	E48; //  Напряжение батарейки ниже 2,65(В)
};

// состав прибора
//SOFTVERSION	 	VERSIONSOFT	 	2.3.4 Чтение версии ПО счётчика. SOFTVERSION
//PRODUCTIONVAR	 	VARPRODUCTION	2.3.16 Чтение варианта исполнения. PRODUCTIONVAR
//KOEFTRANSFORM	 	TRANSFORMKOEF	2.3.3 Чтение коэффициента трансформации счётчика. KOEFTRANSFORM
struct PRODUCTVARNO
{
    double	Un;		// Номинальное напряжение, В
    double	In;		// Номинальный ток, А
    double	Imax;	// Максимальный ток, А
    int		MConst;	// Постоянная счетчика, имп./кВт*ч
};
#define CONSISTSOFTVERLEN 16
#define CONSISTMETERTYPE 4
#define CONSISTTARIFICATOR 4
#define CONSISTSYMPHASE 4
#define CONSISTIFACE 8
#define CONSISTMEM3 8
struct CONSIST
{
    char			SoftVer[CONSISTSOFTVERLEN]; 	// версия ПО счётчика
    double			In;          	// Iн Iн - номинальный ток А: 0 - 5; 1 - 1; 2 - 10.
    double			Un;          	// Uн Uн - номинальное напряжение В: 0 - 57,7; 1 - 230.
    double			ClR;         	// Cl R класс точности по реактивной энергии %: 0 - 0,2; 1 - 0,5; 2 - 1,0; 3 - 2,0.
    double			ClA;	     	// Cl А класс точности по активной энергии %: 0 - 0,2; 1 - 0,5; 2 - 1,0; 3 - 2,0.
//---------------------------------
    int				MeterConst;  	// Постоянная счетчика имп/квт?ч 0 - 5000; 1 - 25000; 2 - 1250; 3 - 500; 4 - 1000; 5 - 250.
    int				NPhase;      	// Число фаз 0 - 3, 1 - 1
    bool			ProfMPower;  	// Учет профиля средних мощностей 0 - нет, 1 - да
    int				TempRange;   	// Температурный диапазон°C 0 – 20, 1 – 40
    int				NDirect;     	// Число направлений 0 - 2, 1 - 1
//---------------------------------
    PRODUCTVARNO	NVarProd;    	// No варианта исполнения 1 - 57,7В_(1)5А_10А_5000имп./кВт*ч 2 - 230В5А60А500имп./кВт*ч 3 - 230В5А100А250имп./кВт*ч 4 - 230В(1)5А10А1000имп./кВт*ч
    char			MeterType[CONSISTMETERTYPE];	// Тип счетчика 0 - AR, 1 - A
    char			Tarificator[CONSISTTARIFICATOR];	// Тарификатор 0 - внешний, 1 - внутренний
    char			SumPhase[CONSISTSYMPHASE];    // Суммирование фаз 0 - с учетом знака, 1 - по модулю
//---------------------------------
    bool			EPlonb;         // Эл. помба верхней крышки 0 - нет, 1 - есть
    bool			ExSupp;         // Внешнее питание 0 - нет, 1 - есть
    char			IFace[CONSISTIFACE];       // Интерфейс 0 - CAN, 1 - RS-485, 2 - резерв, 3 - нет
    bool			OPort;          // оптопорт 0 - нет, 1 - есть
    bool			ModemGSM;       // Модем GSM 0 - нет, 1 - есть
    bool			ModemPLM;       // Модем PLM 0 - нет, 1 - есть
    char			Mem3[CONSISTMEM3];        // Память No3 0 - 65.5x8, 1 - 131x8
//---------------------------------
    bool			PhCalcPower;    // Пофазный учет энергии A+ 0 - нет, 1 - да
    bool			QPower;         // Контроль ПКЭ 0 - нет, 1 - да
    bool			SupIF1;         // Встроенное питание интерфейса 1 0 - нет, 1 - да
    bool			IFace2;         // Интерфейс 2 0 - нет, 1 - да
    bool			CEPlomb;        // Флаг наличия эл. пломбы защитной крышки, 0 - нет, 1 - есть
    bool			TarMax;         // Флаг потарифного учета максимумов мощности, 0 - нет, 1 - есть
    bool			Light;          // Флаг наличия подсветки ЖКИ, 0 - нет, 1 - есть
    bool			Relay;          // Флаг наличия встроенного реле, 0 - нет, 1 - есть
//---------------------------------
    bool			ExControl;      // Флаг наличия аппаратных средств управления внешними устройствами отключения нагрузки, 0 - нет, 1 - есть
    bool			VoltTarif;      // Флаг переключения тарифов внешним напряжением, 0 - нет, 1 - да
    bool			BEPlomb;        // Флаг наличия эл.пломбы модульного отсека, 0 - нет, 1 - есть
    bool			Profile2;       // Флаг наличия профиля 2 0 - нет, 1 - есть
    bool			ModemPLC2;      // Модем PLC2, 0 - нет, 1 - есть
    bool			IEC61107;       // Флаг протокола IEC61107, 0 - нет, 1 - да
    double			Kvolt; 			// Коэффициент трансформации по напряжению
    double			Kcurr; 			// Коэффициент трансформации по току
};

//энергетические параметры
//VOLTAGE3PHASE	 	PHASE3VOLTAGE	 	//2.3.15.2 Ответ прибора на запрос чтения напряжения. VOLTAGE3PHASE
//CURRENT3PHASE	 	PHASE3CURRENT	 	//2.3.15.2 Ответ прибора на запрос чтения тока. CURRENT3PHASE
//ANGLE3PHASE	 	PHASE3ANGLE		//2.3.15.2 Ответ прибора на запрос чтения углов между фазными напряжениями. ANGLE3PHASE
//KOEFPOWER3PHASE	 	PHASE3KOEFPOWER	 	//2.3.15.3 Ответ прибора на запрос чтения коэффициентов мощности KOEFPOWER3PHASE
//POWER3PHASE	 	PHASE3POWER	 	//2.3.15.1 Ответ прибора на запрос чтения Активной мощности P(Ватт). POWER3PHASE
//POWER3PHASE	 	PHASE3POWER	 	//2.3.15.1 Ответ прибора на запрос чтения Реактивной мощности Q(ВАр - Вольт Ампер реактивный). POWER3PHASE
//POWER3PHASE	 	PHASE3POWER	 	//2.3.15.1 Ответ прибора на запрос чтения Полной мощности S(ВА - Вольт Ампер). POWER3PHASE
//FREQUENCY	 	double	 		//2.3.15.4 Ответ прибора на запрос чтения частоты FREQUENCY
//KOEFPHASEDISTORT3PHASE 	PHASE3KOEFPHASEDISTORT	//2.3.15.5 Ответ прибора на запрос чтения коэффициентов искажения синусоидальности фазных напряжений. KOEFPHASEDISTORT3PHASE
struct PHASE3
{
    double	Phase1;
    double	Phase2;
    double	Phase3;
};
struct PHASE3SUM
{
    double	SumPhase;
    double	Phase1;
    double	Phase2;
    double	Phase3;
};
struct DIRECTPHASE3SUM
{
    int	SumPhase;
    int	Phase1;
    int	Phase2;
    int	Phase3;
};
struct ELECTROVAL
{
    PHASE3			Voltage;
    PHASE3			Current;
    PHASE3			Angle;
    PHASE3SUM		PowerFactor;
    DIRECTPHASE3SUM	KADirect;
    DIRECTPHASE3SUM	KRDirect;
    PHASE3SUM		PPower;
    DIRECTPHASE3SUM	PADirect;
    PHASE3SUM		QPower;
    DIRECTPHASE3SUM	QRDirect;
    PHASE3SUM		SPower;
    DIRECTPHASE3SUM	SADirect;
    DIRECTPHASE3SUM	SRDirect;
    double		Frequency;
    PHASE3		Distortion;
};

//TIMEOFMETER	 	TDateTime	 	//2.1.1 Чтение текущего времени. TIMEOFMETER

//2.1.1 Чтение текущего времени. TIMEOFMETER
//Поле данных ответа содержит 8 байт 2/10-го кода в последовательности: секунды,
//минуты, часы, день недели, число, месяц, год, признак зима/лето (зима=1, лето=0).
//Ответ: 80 43 14 16 03 27 02 08 01 (CRC) 16:14:43 среда 27 февраля 2008 года, зима.
#pragma pack (push, 1)
struct TIMEOFMETER
{
    unsigned char	Sec;
    unsigned char	Min;
    unsigned char	Hour;
    unsigned char	Week;
    unsigned char	Day;
    unsigned char	Month;
    unsigned char	Year;
    unsigned char	Winter;
};
#pragma pack (pop)
#define TIMEOFMETERLEN sizeof(TIMEOFMETER)
#define EXPECT_TIMEOFMETERLEN 8

//2.3.4 Чтение версии ПО счётчика. SOFTVERSION
//В ответ на запрос счетчик возвращает 3 байта 2/10-го кода в поле данных ответа.
//Ответ: 80 09 00 00 (CRC) Версия ПО: 9.0.0
#pragma pack (push, 1)
struct SOFTVERSION
{
    unsigned char SV1;
    unsigned char SV2;
    unsigned char SV3;
};
#pragma pack (pop)
#define SOFTVERSIONLEN sizeof(SOFTVERSION)
#define EXPECT_SOFTVERSIONLEN 3

//2.3.11 Чтение слова состояния. STATEWORD
//Поле данных ответа состоит из 6 байт.
#pragma pack (push, 1)
struct STATEWORD
{
    unsigned char	E33:1; //  Повреждены регистры среза
    unsigned char	E34:1; //  Ошибка указателей журнала событий
    unsigned char	E35:1; //  Ошибка записи журнала событий
    unsigned char	E36:1; //  Повреждение регистра учета технических потерь
    unsigned char	E37:1; //  Ошибка мощностей технических потерь
    unsigned char	E38:1; //  Ошибка регистров накопленной энергии потерь
    unsigned char	E39:1; //  Повреждены регистры пофазного учета
    unsigned char	E40:1; //  Флаг поступления широковещ. сообщения
//-------------------
    unsigned char	E41:1; //  Повреждение указателей журнала ПКЭ
    unsigned char	E42:1; //  Ошибка записи журнала ПКЭ
    unsigned char	E43:1; //
    unsigned char	E44:1; //
    unsigned char	E45:1; //
    unsigned char	E46:1; //
    unsigned char	E47:1; //  Выполнение процедуры коррекции времени
    unsigned char	E48:1; //  Напряжение батарейки ниже 2,65(В)
//-------------------
    unsigned char	E17:1; //  Поврежден флаг отключения нагрузки
    unsigned char	E18:1; //  Ошибка лимита мощности
    unsigned char	E19:1; //  Ошибка лимита энергии
    unsigned char	E20:1; //  Нарушение параметров UART
    unsigned char	E21:1; //  Ошибка параметров индикации по тарифам
    unsigned char	E22:1; //  Ошибка параметров индикации по периодам
    unsigned char	E23:1; //  Повреждение множителя таймаута
    unsigned char	E24:1; //  Поврежден байт программируемых флагов
//-------------------
    unsigned char	E25:1; //  Повреждено расписание праздничных дней
    unsigned char	E26:1; //  Повреждено тарифное расписание
    unsigned char	E27:1; //  Поврежден массив таймера
    unsigned char	E28:1; //  Ошибка сезонных переходов
    unsigned char	E29:1; //  Ошибка местоположения прибора
    unsigned char	E30:1; //  Повреждены коэффициенты трансформации
    unsigned char	E31:1; //  Повреждены регистры накопления
    unsigned char	E32:1; //  Ошибка параметров среза
//-------------------
    unsigned char	E01:1; //  Напряжение батарейки ниже 2,2(В)
    unsigned char	E02:1; //  Нарушено функционирование памяти2
    unsigned char	E03:1; //  Нарушено функционирование UART
    unsigned char	E04:1; //  Нарушено функционирование ADS
    unsigned char	E05:1; //  Ошибка обмена с памятью1
    unsigned char	E06:1; //  Неисправность часов
    unsigned char	E07:1; //  Нарушено функционирование памяти3
    unsigned char	E08:1; //
//-------------------
    unsigned char	E09:1; //  Ошибка КС ПО
    unsigned char	E10:1; //  Ошибка калибровочных коэффициентов
    unsigned char	E11:1; //  Ошибка регистров накопленной энергии
    unsigned char	E12:1; //  Ошибка сетевого адреса
    unsigned char	E13:1; //  Ошибка серийного номера
    unsigned char	E14:1; //  Поврежден пароль
    unsigned char	E15:1; //  Ошибка массива вариантов исполнения
    unsigned char	E16:1; //  Поврежден флаг тарификатора
};
#pragma pack (pop)
#define STATEWORDLEN sizeof(STATEWORD)
#define EXPECT_STATEWORDLEN 6

//2.3.16 Чтение варианта исполнения. PRODUCTIONVAR
//Поле данных ответа состоит из 6 байт
#pragma pack (push, 1)
struct PRODUCTIONVAR
{
    unsigned char In:2;             // Iн Iн - номинальный ток А: 0 - 5; 1 - 1; 2 - 10.
    unsigned char Un:2;             // Uн Uн - номинальное напряжение В: 0 - 57,7; 1 - 230.
    unsigned char ClR:2;            // Cl R класс точности по реактивной энергии %: 0 - 0,2; 1 - 0,5; 2 - 1,0; 3 - 2,0.
    unsigned char ClA:2;            // Cl А класс точности по активной энергии %: 0 - 0,2; 1 - 0,5; 2 - 1,0; 3 - 2,0.
//---------------------------------
    unsigned char MeterConst:4;     // Постоянная счетчика имп/квт?ч 0 - 5000; 1 - 25000; 2 - 1250; 3 - 500; 4 - 1000; 5 - 250.
    unsigned char NPhase:1;         // Число фаз 0 - 3, 1 - 1
    unsigned char ProfMPower:1;     // Учет профиля средних мощностей 0 - нет, 1 - да
    unsigned char TempRange:1;      // Температурный диапазон°C 0 – 20, 1 – 40
    unsigned char NDirect:1;        // Число направлений 0 - 2, 1 - 1
//---------------------------------
    unsigned char NVarProd:4;       // No варианта исполнения 1 - 57,7В(1)5А10А5000имп./кВт*ч 2 - 230В5А60А500имп./кВт*ч 3 - 230В5А100А250имп./кВт*ч 4 - 230В(1)5А10А1000имп./кВт*ч
    unsigned char MeterType:2;      // Тип счетчика 0 - AR, 1 - A
    unsigned char Tarificator:1;    // Тарификатор 0 - внешний, 1 - внутренний
    unsigned char SumPhase:1;       // Суммирование фаз 0 - с учетом знака, 1 - по модулю
//---------------------------------
    unsigned char EPlonb:1;         // Эл. помба верхней крышки 0 - нет, 1 - есть
    unsigned char ExSupp:1;         // Внешнее питание 0 - нет, 1 - есть
    unsigned char IFace:2;          // Интерфейс 0 - CAN, 1 - RS-485, 2 - резерв, 3 - нет
    unsigned char OPort:1;          // оптопорт 0 - нет, 1 - есть
    unsigned char ModemGSM:1;       // Модем GSM 0 - нет, 1 - есть
    unsigned char ModemPLM:1;       // Модем PLM 0 - нет, 1 - есть
    unsigned char Mem3:1;           // Память No3 0 - 65.5x8, 1 - 131x8
//---------------------------------
    unsigned char PhCalcPower:1;    // Пофазный учет энергии A+ 0 - нет, 1 - да
    unsigned char QPower:1;         // Контроль ПКЭ 0 - нет, 1 - да
    unsigned char SupIF1:1;         // Встроенное питание интерфейса 1 0 - нет, 1 - да
    unsigned char IFace2:1;         // Интерфейс 2 0 - нет, 1 - да
    unsigned char CEPlomb:1;        // Флаг наличия эл. пломбы защитной крышки, 0 - нет, 1 - есть
    unsigned char TarMax:1;         // Флаг потарифного учета максимумов мощности, 0 - нет, 1 - есть
    unsigned char Light:1;          // Флаг наличия подсветки ЖКИ, 0 - нет, 1 - есть
    unsigned char Relay:1;          // Флаг наличия встроенного реле, 0 - нет, 1 - есть
//---------------------------------
    unsigned char ExControl:1;      // Флаг наличия аппаратных средств управления внешними устройствами отключения нагрузки, 0 - нет, 1 - есть
    unsigned char VoltTarif:1;      // Флаг переключения тарифов внешним напряжением, 0 - нет, 1 - да
    unsigned char BEPlomb:1;        // Флаг наличия эл.пломбы модульного отсека, 0 - нет, 1 - есть
    unsigned char Profile2:1;       // Флаг наличия профиля 2 0 - нет, 1 - есть
    unsigned char ModemPLC2:1;      // Модем PLC2, 0 - нет, 1 - есть
    unsigned char IEC61107:1;       // Флаг протокола IEC61107, 0 - нет, 1 - да
    unsigned char Reserved1:1;      // Reserved
    unsigned char Reserved2:1;      // Reserved
};
#pragma pack (pop)
#define PRODUCTIONVARLEN sizeof(PRODUCTIONVAR)
#define EXPECT_PRODUCTIONVARLEN 6

//2.3.3 Чтение коэффициента трансформации счётчика. KOEFTRANSFORM
//В ответ на запрос счетчик возвращает 4 байта в поле данных ответа в последовательности:
//два двоичных байта Кн, два двоичных байта Кт
//Ответ: 80 00 01 00 01 (CRC)
//Коэффициент трансформации по напряжению Кн = 1
//Коэффициент трансформации по току Кт = 1
#pragma pack (push, 1)
struct KOEFTRANSFORM
{
    unsigned char HiKvolt; //Коэффициент трансформации по напряжению Старший байт
    unsigned char LoKvolt; //Коэффициент трансформации по напряжению Младший байт
    unsigned char HiKcurr; //Коэффициент трансформации по току Старший байт
    unsigned char LoKcurr; //Коэффициент трансформации по току Младший байт
};
#pragma pack (pop)
#define KOEFTRANSFORMLEN sizeof(KOEFTRANSFORM)
#define EXPECT_KOEFTRANSFORMLEN 4

#pragma pack (push, 1)
struct BYTE132
{
    unsigned char B1; //байт 1
    unsigned char B3; //байт 3
    unsigned char B2; //байт 2
};
#pragma pack (pop)

//2.3.15 Чтение вспомогательных параметров. VOLTAGE3PHASE
#pragma pack (push, 1)
struct VOLTAGE : BYTE132
{
};
#pragma pack (pop)
#define VOLTAGELEN sizeof(VOLTAGE)
#define EXPECT_VOLTAGELEN 3
#define VOLTAGEMULTIPLIER 100.0

//2.3.15 Чтение вспомогательных параметров. CURRENT3PHASE
#pragma pack (push, 1)
struct CURRENT : BYTE132
{
};
#pragma pack (pop)
#define CURRENTLEN sizeof(CURRENT)
#define EXPECT_CURRENTLEN 3
#define CURRENTMULTIPLIER 1000.0

//2.3.15 Чтение вспомогательных параметров. ANGLE3PHASE
#pragma pack (push, 1)
struct ANGLE : BYTE132
{
};
#pragma pack (pop)
#define ANGLELEN sizeof(ANGLE)
#define EXPECT_ANGLELEN 3
#define ANGLEMULTIPLIER 100.0

#pragma pack (push, 1)
struct BYTE1DD32
{
    unsigned char B1          :6; //байт 1
    unsigned char DirectRPower:1; // Направление реактивной мощности: 0 – прямое; 1 – обратное.
    unsigned char DirectAPower:1; // Направление активной мощности: 0 – прямое; 1 – обратное.
    unsigned char B3          :8; //байт 3
    unsigned char B2          :8; //байт 2
};
#pragma pack (pop)

//2.3.15 Чтение вспомогательных параметров. KOEFPOWER3PHASE
#pragma pack (push, 1)
struct KOEFPOWER : BYTE1DD32
{
};
#pragma pack (pop)
#define KOEFPOWERLEN sizeof(KOEFPOWER)
#define EXPECT_KOEFPOWERLEN 3
#define KOEFPOWERMULTIPLIER 1000.0

//2.3.15 Чтение вспомогательных параметров. POWER3PHASE
#pragma pack (push, 1)
struct POWER : BYTE1DD32
{
};
#pragma pack (pop)
#define POWERLEN sizeof(POWER)
#define EXPECT_POWERLEN 3
#define POWERMULTIPLIER 100.0

//2.3.15 Чтение вспомогательных параметров. FREQUENCY
#pragma pack (push, 1)
struct FREQUENCY : BYTE132
{
};
#pragma pack (pop)
#define FREQUENCYLEN sizeof(FREQUENCY)
#define EXPECT_FREQUENCYLEN 3
#define FREQUENCYMULTIPLIER 100.0

//2.3.15 Чтение вспомогательных параметров. KOEFPHASEDISTORT3PHASE
#pragma pack (push, 1)
struct KOEFPHASEDISTORT
{
    unsigned char LoKpd; //Коэффициент искажения синусоидальности фазных напряжений Младший байт
    unsigned char HiKpd; //Коэффициент искажения синусоидальности фазных напряжений Старший байт
};
#pragma pack (pop)
#define KOEFPHASEDISTORTLEN sizeof(KOEFPHASEDISTORT)
#define EXPECT_KOEFPHASEDISTORTLEN 2
#define KOEFPHASEDISTORTMULTIPLIER 100.0

//2.3.15 Чтение вспомогательных параметров. TEMPERATURE
#pragma pack (push, 1)
struct TEMPERATURE
{
    unsigned char HiT; //Температура внутри корпуса прибора Старший байт
    unsigned char LoT; //Температура внутри корпуса прибора Младший байт
};
#pragma pack (pop)
#define TEMPERATURELEN sizeof(TEMPERATURE)
#define EXPECT_TEMPERATURELEN 2

struct ELECTROMETERDATA
{
    unsigned char	Address;
    TDateTime		ServerTime;
    METERDATETIME	MeterTime;
    bool			flagMeterTime;
    ELECTROVAL		ElectroVal;
    bool			flagMeterElectroVal;
    CONDITION		Condition;
    bool			flagMeterCondition;
    CONSIST			Consist;
    bool			flagMeterConsist;
};


#endif // METERVALUE_H
