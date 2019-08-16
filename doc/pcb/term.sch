EESchema Schematic File Version 4
LIBS:term-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F0:STM32F030F4Px U3
U 1 1 5D33AA8B
P 5500 3500
F 0 "U3" H 5500 2611 50  0000 C CNN
F 1 "STM32F030F4Px" H 5500 2520 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 5100 2800 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00088500.pdf" H 5500 3500 50  0001 C CNN
	1    5500 3500
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:CA56-12CGKWA U4
U 1 1 5D33B78F
P 9000 3650
F 0 "U4" H 9000 4317 50  0000 C CNN
F 1 "CA56-12CGKWA" H 9000 4226 50  0000 C CNN
F 2 "Display_7Segment:CA56-12CGKWA" H 9000 3050 50  0001 C CNN
F 3 "http://www.kingbright.com/attachments/file/psearch/000/00/00/CA56-12CGKWA(Ver.9A).pdf" H 8570 3680 50  0001 C CNN
	1    9000 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2350 5500 2800
Wire Wire Line
	5500 2350 5600 2350
Connection ~ 5500 2350
$Comp
L Device:R R2
U 1 1 5D3413A8
P 4950 2700
F 0 "R2" H 5020 2746 50  0000 L CNN
F 1 "10k" H 5020 2655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4880 2700 50  0001 C CNN
F 3 "~" H 4950 2700 50  0001 C CNN
	1    4950 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2550 4950 2350
Connection ~ 4950 2350
Wire Wire Line
	4950 2350 5500 2350
Wire Wire Line
	4950 2850 4950 3000
Wire Wire Line
	4950 3000 5000 3000
Wire Wire Line
	5000 3200 4200 3200
$Comp
L power:GND #PWR0102
U 1 1 5D342550
P 4200 4500
F 0 "#PWR0102" H 4200 4250 50  0001 C CNN
F 1 "GND" H 4205 4327 50  0000 C CNN
F 2 "" H 4200 4500 50  0001 C CNN
F 3 "" H 4200 4500 50  0001 C CNN
	1    4200 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4300 4200 4300
Wire Wire Line
	4200 4300 4200 4500
$Comp
L Device:R R1
U 1 1 5D343071
P 4200 3650
F 0 "R1" H 4270 3696 50  0000 L CNN
F 1 "10k" H 4270 3605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4130 3650 50  0001 C CNN
F 3 "~" H 4200 3650 50  0001 C CNN
	1    4200 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3200 4200 3500
Wire Wire Line
	4200 3800 4200 4300
Connection ~ 4200 4300
Text GLabel 6300 3900 2    50   Input ~ 0
SC
Text GLabel 6300 3800 2    50   Input ~ 0
SD
Text GLabel 6300 3600 2    50   Input ~ 0
SB
Text GLabel 6300 3500 2    50   Input ~ 0
SA
Text GLabel 6300 3400 2    50   Input ~ 0
SG
Text GLabel 6250 3300 2    50   Input ~ 0
D1
Wire Wire Line
	6250 3300 6000 3300
Text GLabel 6250 3200 2    50   Input ~ 0
D2
Wire Wire Line
	6250 3200 6000 3200
Text GLabel 6250 3100 2    50   Input ~ 0
D3
Text GLabel 6250 3000 2    50   Input ~ 0
D4
Wire Wire Line
	6000 3000 6250 3000
Wire Wire Line
	6000 3100 6250 3100
Text GLabel 4700 3800 0    50   Input ~ 0
SF
Text GLabel 4700 3900 0    50   Input ~ 0
SE
NoConn ~ 6000 4000
NoConn ~ 6000 4100
NoConn ~ 5000 4100
Text GLabel 7900 3350 0    50   Input ~ 0
SA
Text GLabel 7900 3450 0    50   Input ~ 0
SB
Text GLabel 7900 3550 0    50   Input ~ 0
SC
Text GLabel 7900 3650 0    50   Input ~ 0
SD
Text GLabel 7900 3750 0    50   Input ~ 0
SE
Text GLabel 7900 3850 0    50   Input ~ 0
SF
Text GLabel 7900 3950 0    50   Input ~ 0
SG
NoConn ~ 7900 4050
Text GLabel 10100 3750 2    50   Input ~ 0
D1
Text GLabel 10100 3850 2    50   Input ~ 0
D2
Text GLabel 10100 3950 2    50   Input ~ 0
D3
Text GLabel 10100 4050 2    50   Input ~ 0
D4
$Comp
L Regulator_Linear:LM1117-3.3 U2
U 1 1 5D3528B6
P 3450 2350
F 0 "U2" H 3450 2592 50  0000 C CNN
F 1 "LM1117-3.3" H 3450 2501 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 3450 2350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 3450 2350 50  0001 C CNN
	1    3450 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 2400 2400 2350
Wire Wire Line
	2400 2350 2850 2350
Wire Wire Line
	2400 2800 2850 2800
Wire Wire Line
	3450 2800 3450 2650
$Comp
L Device:C C1
U 1 1 5D353BC5
P 2850 2500
F 0 "C1" H 2965 2546 50  0000 L CNN
F 1 "100n" H 2965 2455 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D10.5mm_W5.0mm_P5.00mm" H 2888 2350 50  0001 C CNN
F 3 "~" H 2850 2500 50  0001 C CNN
	1    2850 2500
	1    0    0    -1  
$EndComp
Connection ~ 2850 2350
Wire Wire Line
	2850 2350 3150 2350
$Comp
L Device:C C2
U 1 1 5D3541D8
P 4050 2500
F 0 "C2" H 4165 2546 50  0000 L CNN
F 1 "100n" H 4165 2455 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D8.0mm_W5.0mm_P7.50mm" H 4088 2350 50  0001 C CNN
F 3 "~" H 4050 2500 50  0001 C CNN
	1    4050 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2350 4050 2350
Wire Wire Line
	4050 2650 4050 2800
Wire Wire Line
	4050 2800 3450 2800
Connection ~ 3450 2800
Wire Wire Line
	2850 2650 2850 2800
Connection ~ 2850 2800
Wire Wire Line
	2850 2800 3450 2800
$Comp
L power:+5V #PWR0106
U 1 1 5D35634A
P 2400 2350
F 0 "#PWR0106" H 2400 2200 50  0001 C CNN
F 1 "+5V" H 2415 2523 50  0000 C CNN
F 2 "" H 2400 2350 50  0001 C CNN
F 3 "" H 2400 2350 50  0001 C CNN
	1    2400 2350
	1    0    0    -1  
$EndComp
Connection ~ 2400 2350
$Comp
L Device:L L1
U 1 1 5D3F8A5D
P 5600 2650
F 0 "L1" H 5653 2696 50  0000 L CNN
F 1 "10uH" H 5653 2605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5600 2650 50  0001 C CNN
F 3 "~" H 5600 2650 50  0001 C CNN
	1    5600 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2350 5600 2500
Wire Wire Line
	4050 2350 4950 2350
Connection ~ 4050 2350
$Comp
L Sensor_Temperature:LM35-LP U1
U 1 1 5D4616F8
P 7100 2650
F 0 "U1" H 6771 2696 50  0000 R CNN
F 1 "LM35-LP" H 6771 2605 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92" H 7150 2400 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm35.pdf" H 7100 2650 50  0001 C CNN
	1    7100 2650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5D463DDB
P 7100 2350
F 0 "#PWR01" H 7100 2200 50  0001 C CNN
F 1 "+5V" H 7115 2523 50  0000 C CNN
F 2 "" H 7100 2350 50  0001 C CNN
F 3 "" H 7100 2350 50  0001 C CNN
	1    7100 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5D46527D
P 7100 3300
F 0 "#PWR02" H 7100 3050 50  0001 C CNN
F 1 "GND" H 7105 3127 50  0000 C CNN
F 2 "" H 7100 3300 50  0001 C CNN
F 3 "" H 7100 3300 50  0001 C CNN
	1    7100 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2650 7500 3250
Wire Wire Line
	7100 2950 7100 3250
$Comp
L Device:C C3
U 1 1 5D46BEF6
P 7250 3250
F 0 "C3" V 6998 3250 50  0000 C CNN
F 1 "100n" V 7089 3250 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D8.0mm_W5.0mm_P7.50mm" H 7288 3100 50  0001 C CNN
F 3 "~" H 7250 3250 50  0001 C CNN
	1    7250 3250
	0    1    1    0   
$EndComp
Connection ~ 7100 3250
Wire Wire Line
	7100 3250 7100 3300
Wire Wire Line
	7400 3250 7500 3250
Connection ~ 7500 3250
Wire Wire Line
	7500 3250 7500 3700
$Comp
L Device:R R5
U 1 1 5D47B614
P 6150 3400
F 0 "R5" V 6600 4000 50  0000 C CNN
F 1 "470" V 6700 4000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6080 3400 50  0001 C CNN
F 3 "~" H 6150 3400 50  0001 C CNN
	1    6150 3400
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5D47BA9F
P 6150 3500
F 0 "R6" V 6700 4100 50  0000 C CNN
F 1 "470" V 6800 4100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6080 3500 50  0001 C CNN
F 3 "~" H 6150 3500 50  0001 C CNN
	1    6150 3500
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 5D47BE23
P 6150 3600
F 0 "R7" V 6800 4200 50  0000 C CNN
F 1 "470" V 6900 4200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6080 3600 50  0001 C CNN
F 3 "~" H 6150 3600 50  0001 C CNN
	1    6150 3600
	0    1    1    0   
$EndComp
$Comp
L Device:R R9
U 1 1 5D47C4A1
P 6150 3800
F 0 "R9" V 6200 4650 50  0000 C CNN
F 1 "470" V 6300 4650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6080 3800 50  0001 C CNN
F 3 "~" H 6150 3800 50  0001 C CNN
	1    6150 3800
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 5D47C5F5
P 6150 3900
F 0 "R10" V 6300 4750 50  0000 C CNN
F 1 "470" V 6400 4750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6080 3900 50  0001 C CNN
F 3 "~" H 6150 3900 50  0001 C CNN
	1    6150 3900
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5D47F814
P 4850 3800
F 0 "R3" V 4650 3800 50  0000 C CNN
F 1 "470" V 4750 3800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4780 3800 50  0001 C CNN
F 3 "~" H 4850 3800 50  0001 C CNN
	1    4850 3800
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5D47FC97
P 4850 3900
F 0 "R4" V 4950 3900 50  0000 C CNN
F 1 "470" V 5050 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4780 3900 50  0001 C CNN
F 3 "~" H 4850 3900 50  0001 C CNN
	1    4850 3900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5D497D16
P 2850 2800
F 0 "#PWR0101" H 2850 2550 50  0001 C CNN
F 1 "GND" H 2855 2627 50  0000 C CNN
F 2 "" H 2850 2800 50  0001 C CNN
F 3 "" H 2850 2800 50  0001 C CNN
	1    2850 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3700 7500 3700
$Comp
L Connector:USB_B_Micro J1
U 1 1 5D4BA4CA
P 1800 2600
F 0 "J1" H 1857 3067 50  0000 C CNN
F 1 "USB_B_Micro" H 1857 2976 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex_47346-0001" H 1950 2550 50  0001 C CNN
F 3 "~" H 1950 2550 50  0001 C CNN
	1    1800 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2400 2400 2400
Wire Wire Line
	1800 3000 2400 3000
Wire Wire Line
	2400 3000 2400 2800
NoConn ~ 1700 3000
NoConn ~ 2100 2800
NoConn ~ 2100 2700
NoConn ~ 2100 2600
$EndSCHEMATC
