    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Assignment1_V6_P)
        ;%
            section.nData     = 31;
            section.data(31)  = dumData; %prealloc

                    ;% Assignment1_V6_P.FXOS87006AxesSensor_SampleTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_P.AnalogInput_SampleTime
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V6_P.AnalogInput1_SampleTime
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V6_P.DigitalRead_SampleTime
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V6_P.DigitalRead1_SampleTime
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V6_P.Constant10_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V6_P.Constant_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V6_P.Constant5_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V6_P.Constant9_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V6_P.Constant1_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V6_P.Constant3_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V6_P.Constant2_Value
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% Assignment1_V6_P.Constant4_Value
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% Assignment1_V6_P.Constant6_Value
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% Assignment1_V6_P.Constant7_Value
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% Assignment1_V6_P.Constant8_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% Assignment1_V6_P.Gain_Gain
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% Assignment1_V6_P.Constant_Value_d
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% Assignment1_V6_P.Constant2_Value_o
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 20;

                    ;% Assignment1_V6_P.Constant1_Value_j
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 22;

                    ;% Assignment1_V6_P.Gain_Gain_e
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 23;

                    ;% Assignment1_V6_P.Multiply2_Gain
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 24;

                    ;% Assignment1_V6_P.Gain11_Gain
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 25;

                    ;% Assignment1_V6_P.Multiply_Gain
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 26;

                    ;% Assignment1_V6_P.Multiply1_Gain
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 27;

                    ;% Assignment1_V6_P.Constant1_Value_b
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 28;

                    ;% Assignment1_V6_P.Gain1_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 29;

                    ;% Assignment1_V6_P.Gain3_Gain
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 30;

                    ;% Assignment1_V6_P.Gain_Gain_d
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 31;

                    ;% Assignment1_V6_P.Gain2_Gain
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 32;

                    ;% Assignment1_V6_P.Constant_Value_g
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 33;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Assignment1_V6_P.Gain16_Gain
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_P.Gain15_Gain
                    section.data(2).logicalSrcIdx = 32;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V6_P.Gain2_Gain_g
                    section.data(3).logicalSrcIdx = 33;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V6_P.Gain7_Gain
                    section.data(4).logicalSrcIdx = 34;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V6_P.Gain8_Gain
                    section.data(5).logicalSrcIdx = 35;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V6_P.Gain6_Gain
                    section.data(6).logicalSrcIdx = 36;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V6_P.Gain1_Gain_m
                    section.data(7).logicalSrcIdx = 37;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V6_P.Gain3_Gain_o
                    section.data(8).logicalSrcIdx = 38;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V6_P.Gain_Gain_l
                    section.data(9).logicalSrcIdx = 39;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V6_P.Gain4_Gain
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_P.Gain5_Gain
                    section.data(2).logicalSrcIdx = 41;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 10;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Assignment1_V6_B)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% Assignment1_V6_B.Constant
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_B.Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% Assignment1_V6_B.Multiply2
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Assignment1_V6_B.Gain11
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Assignment1_V6_B.Multiply
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% Assignment1_V6_B.Multiply1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% Assignment1_V6_B.sense_timeout_threshold
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% Assignment1_V6_B.Motion_State
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% Assignment1_V6_B.smoothed_output
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 10;

                    ;% Assignment1_V6_B.red
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 11;

                    ;% Assignment1_V6_B.blue
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 12;

                    ;% Assignment1_V6_B.green
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 13;

                    ;% Assignment1_V6_B.AnalogInput1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 14;

                    ;% Assignment1_V6_B.AnalogInput
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Assignment1_V6_B.Gain2
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_B.VectorConcatenate1
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment1_V6_B.Gain1
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 4;

                    ;% Assignment1_V6_B.Gain_j
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 5;

                    ;% Assignment1_V6_B.PACING_REF_PWM
                    section.data(5).logicalSrcIdx = 18;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V6_B.Cast9
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V6_B.Cast8
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V6_B.Cast10
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V6_B.Cast7
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V6_B.Gain4
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_B.Gain5
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V6_B.DataTypeConversion1
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_B.DataTypeConversion
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Assignment1_V6_B.Cast
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_B.IntegertoBitConverter
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 15;

                    ;% Assignment1_V6_B.BittoIntegerConverter1
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 23;

                    ;% Assignment1_V6_B.VectorConcatenate2
                    section.data(4).logicalSrcIdx = 30;
                    section.data(4).dtTransOffset = 27;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment1_V6_B.VectorConcatenate
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_B.ATR_PACE_CTRL
                    section.data(2).logicalSrcIdx = 32;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment1_V6_B.VENT_PACE_CTRL
                    section.data(3).logicalSrcIdx = 33;
                    section.data(3).dtTransOffset = 3;

                    ;% Assignment1_V6_B.PACE_CHARGE_CTRL
                    section.data(4).logicalSrcIdx = 34;
                    section.data(4).dtTransOffset = 4;

                    ;% Assignment1_V6_B.PACE_GND_CTRL
                    section.data(5).logicalSrcIdx = 35;
                    section.data(5).dtTransOffset = 5;

                    ;% Assignment1_V6_B.ATR_GND_CTRL
                    section.data(6).logicalSrcIdx = 36;
                    section.data(6).dtTransOffset = 6;

                    ;% Assignment1_V6_B.VENT_GND_CTRL
                    section.data(7).logicalSrcIdx = 37;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 11;
        sectIdxOffset = 10;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Assignment1_V6_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.obj_n
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_DW.obj_h
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.obj_d
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_DW.obj_a
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.obj_f
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_DW.obj_ni
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V6_DW.obj_g
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V6_DW.obj_e
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V6_DW.obj_m
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V6_DW.obj_b
                    section.data(6).logicalSrcIdx = 10;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V6_DW.obj_h5
                    section.data(7).logicalSrcIdx = 11;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V6_DW.obj_p
                    section.data(8).logicalSrcIdx = 12;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V6_DW.obj_k
                    section.data(9).logicalSrcIdx = 13;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V6_DW.obj_l
                    section.data(10).logicalSrcIdx = 14;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V6_DW.obj_bo
                    section.data(11).logicalSrcIdx = 15;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V6_DW.obj_j
                    section.data(12).logicalSrcIdx = 16;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.obj_ng
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_DW.obj_lo
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V6_DW.obj_dw
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.rolling_avg
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_DW.init_counter
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Integ.AQHandles
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Bitto.AQHandles
                    section.data(2).logicalSrcIdx = 27;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Gain2.AQHandles
                    section.data(3).logicalSrcIdx = 28;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_RATE_.AQHandles
                    section.data(4).logicalSrcIdx = 29;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Multi.AQHandles
                    section.data(5).logicalSrcIdx = 30;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_MATLA.AQHandles
                    section.data(6).logicalSrcIdx = 31;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_MAT_b.AQHandles
                    section.data(7).logicalSrcIdx = 32;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Cast8.AQHandles
                    section.data(8).logicalSrcIdx = 33;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Gain1.AQHandles
                    section.data(9).logicalSrcIdx = 34;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Gain_.AQHandles
                    section.data(10).logicalSrcIdx = 35;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Vecto.AQHandles
                    section.data(11).logicalSrcIdx = 36;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Vec_a.AQHandles
                    section.data(12).logicalSrcIdx = 37;
                    section.data(12).dtTransOffset = 11;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Analo.AQHandles
                    section.data(13).logicalSrcIdx = 38;
                    section.data(13).dtTransOffset = 12;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_DataT.AQHandles
                    section.data(14).logicalSrcIdx = 39;
                    section.data(14).dtTransOffset = 13;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Dat_j.AQHandles
                    section.data(15).logicalSrcIdx = 40;
                    section.data(15).dtTransOffset = 14;

                    ;% Assignment1_V6_DW.TAQSigLogging_InsertedFor_Ana_g.AQHandles
                    section.data(16).logicalSrcIdx = 41;
                    section.data(16).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.sfEvent_l
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.is_c9_Assignment1_V6
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_DW.is_c3_Assignment1_V6
                    section.data(2).logicalSrcIdx = 45;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V6_DW.is_finally_c3_Assignment1_V6
                    section.data(3).logicalSrcIdx = 46;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V6_DW.is_PACE
                    section.data(4).logicalSrcIdx = 47;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V6_DW.is_finally_PACE
                    section.data(5).logicalSrcIdx = 48;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V6_DW.is_SENSE
                    section.data(6).logicalSrcIdx = 49;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V6_DW.is_finally_SENSE
                    section.data(7).logicalSrcIdx = 50;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V6_DW.temporalCounter_i1
                    section.data(8).logicalSrcIdx = 51;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.is_active_c9_Assignment1_V6
                    section.data(1).logicalSrcIdx = 52;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V6_DW.is_active_c3_Assignment1_V6
                    section.data(2).logicalSrcIdx = 53;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V6_DW.tp_Sense_Detect
                    section.data(3).logicalSrcIdx = 54;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V6_DW.tp_Sense_Detected
                    section.data(4).logicalSrcIdx = 55;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V6_DW.tp_Sense_Fail
                    section.data(5).logicalSrcIdx = 56;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V6_DW.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1698407681;
    targMap.checksum1 = 1394021317;
    targMap.checksum2 = 3718237550;
    targMap.checksum3 = 673131672;

