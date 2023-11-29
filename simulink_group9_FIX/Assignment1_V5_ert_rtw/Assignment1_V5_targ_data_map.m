    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
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
        ;% Auto data (Assignment1_V5_P)
        ;%
            section.nData     = 51;
            section.data(51)  = dumData; %prealloc

                    ;% Assignment1_V5_P.FXOS87006AxesSensor_SampleTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_P.AnalogInput_SampleTime
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V5_P.AnalogInput1_SampleTime
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V5_P.DigitalRead_SampleTime
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V5_P.DigitalRead1_SampleTime
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V5_P.Constant2_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V5_P.Constant10_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V5_P.Constant_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V5_P.Constant5_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V5_P.Constant9_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V5_P.Constant1_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V5_P.Constant3_Value
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% Assignment1_V5_P.Constant2_Value_l
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% Assignment1_V5_P.Constant4_Value
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% Assignment1_V5_P.Constant6_Value
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% Assignment1_V5_P.Constant7_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% Assignment1_V5_P.Constant8_Value
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% Assignment1_V5_P.Gain_Gain
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% Assignment1_V5_P.Gain16_Gain
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% Assignment1_V5_P.Gain15_Gain
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% Assignment1_V5_P.Gain9_Gain
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% Assignment1_V5_P.Gain10_Gain
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% Assignment1_V5_P.Gain7_Gain
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% Assignment1_V5_P.Gain8_Gain
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% Assignment1_V5_P.Constant_Value_n
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% Assignment1_V5_P.Constant2_Value_i
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 27;

                    ;% Assignment1_V5_P.Gain2_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 29;

                    ;% Assignment1_V5_P.Constant1_Value_n
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 30;

                    ;% Assignment1_V5_P.Gain_Gain_k
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 31;

                    ;% Assignment1_V5_P.Gain17_Gain
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 32;

                    ;% Assignment1_V5_P.Multiply2_Gain
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 33;

                    ;% Assignment1_V5_P.Gain11_Gain
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 34;

                    ;% Assignment1_V5_P.Gain13_Gain
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 35;

                    ;% Assignment1_V5_P.Gain12_Gain
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 36;

                    ;% Assignment1_V5_P.Gain4_Gain
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 37;

                    ;% Assignment1_V5_P.Gain14_Gain
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 38;

                    ;% Assignment1_V5_P.Gain5_Gain
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 39;

                    ;% Assignment1_V5_P.Gain19_Gain
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 40;

                    ;% Assignment1_V5_P.Multiply_Gain
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 41;

                    ;% Assignment1_V5_P.Gain18_Gain
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 42;

                    ;% Assignment1_V5_P.Multiply1_Gain
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 43;

                    ;% Assignment1_V5_P.Gain6_Gain
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 44;

                    ;% Assignment1_V5_P.Gain1_Gain
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 45;

                    ;% Assignment1_V5_P.Gain3_Gain
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 46;

                    ;% Assignment1_V5_P.Gain_Gain_k2
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 47;

                    ;% Assignment1_V5_P.Constant1_Value_b
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 48;

                    ;% Assignment1_V5_P.Gain1_Gain_b
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 49;

                    ;% Assignment1_V5_P.Gain3_Gain_c
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 50;

                    ;% Assignment1_V5_P.Gain_Gain_e
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 51;

                    ;% Assignment1_V5_P.Gain2_Gain_e
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 52;

                    ;% Assignment1_V5_P.Constant_Value_k
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 53;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
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
        nTotSects     = 9;
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
        ;% Auto data (Assignment1_V5_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V5_B.Constant
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Assignment1_V5_B.Gain2
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_B.VectorConcatenate2
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment1_V5_B.VectorConcatenate1
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% Assignment1_V5_B.Constant2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_B.Gain
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V5_B.Multiply2
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V5_B.Gain11
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V5_B.Gain13
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V5_B.Gain4
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V5_B.Gain5
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V5_B.Multiply
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V5_B.Multiply1
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V5_B.sense_timeout_threshold
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V5_B.tgt
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V5_B.Motion_State
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 11;

                    ;% Assignment1_V5_B.smoothed_output
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 12;

                    ;% Assignment1_V5_B.PACING_REF_PWM
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 13;

                    ;% Assignment1_V5_B.red
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 14;

                    ;% Assignment1_V5_B.blue
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 15;

                    ;% Assignment1_V5_B.green
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 16;

                    ;% Assignment1_V5_B.AnalogInput1
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 17;

                    ;% Assignment1_V5_B.AnalogInput
                    section.data(19).logicalSrcIdx = 22;
                    section.data(19).dtTransOffset = 18;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V5_B.PACE_SENSE_RESPONSE
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V5_B.PACE_SENSE_CHAMBER
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V5_B.PACE_RATE_MODE
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V5_B.PACE_CHAMBER
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V5_B.DataTypeConversion1
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_B.DataTypeConversion
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment1_V5_B.VectorConcatenate
                    section.data(1).logicalSrcIdx = 32;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_B.ATR_PACE_CTRL
                    section.data(2).logicalSrcIdx = 33;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment1_V5_B.VENT_PACE_CTRL
                    section.data(3).logicalSrcIdx = 34;
                    section.data(3).dtTransOffset = 3;

                    ;% Assignment1_V5_B.PACE_CHARGE_CTRL
                    section.data(4).logicalSrcIdx = 35;
                    section.data(4).dtTransOffset = 4;

                    ;% Assignment1_V5_B.PACE_GND_CTRL
                    section.data(5).logicalSrcIdx = 36;
                    section.data(5).dtTransOffset = 5;

                    ;% Assignment1_V5_B.ATR_GND_CTRL
                    section.data(6).logicalSrcIdx = 37;
                    section.data(6).dtTransOffset = 6;

                    ;% Assignment1_V5_B.VENT_GND_CTRL
                    section.data(7).logicalSrcIdx = 38;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
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
        sectIdxOffset = 9;

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
        ;% Auto data (Assignment1_V5_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.obj_i
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_DW.obj_n
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.obj_o
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_DW.obj_b
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.obj_e
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_DW.obj_l
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V5_DW.obj_p
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V5_DW.obj_f
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V5_DW.obj_ng
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V5_DW.obj_lo
                    section.data(6).logicalSrcIdx = 10;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V5_DW.obj_a
                    section.data(7).logicalSrcIdx = 11;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V5_DW.obj_o1
                    section.data(8).logicalSrcIdx = 12;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V5_DW.obj_ej
                    section.data(9).logicalSrcIdx = 13;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V5_DW.obj_bs
                    section.data(10).logicalSrcIdx = 14;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V5_DW.obj_d
                    section.data(11).logicalSrcIdx = 15;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V5_DW.obj_ev
                    section.data(12).logicalSrcIdx = 16;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.obj_j
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_DW.obj_nl
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V5_DW.obj_evb
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.resp_fac_decay
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_DW.resp_fac_grow
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 3;

                    ;% Assignment1_V5_DW.dif
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 6;

                    ;% Assignment1_V5_DW.rolling_avg
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 7;

                    ;% Assignment1_V5_DW.init_counter
                    section.data(5).logicalSrcIdx = 24;
                    section.data(5).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.TAQSigLogging_InsertedFor_RATE_.AQHandles
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_DW.TAQSigLogging_InsertedFor_MATLA.AQHandles
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V5_DW.TAQSigLogging_InsertedFor_MAT_b.AQHandles
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V5_DW.TAQSigLogging_InsertedFor_Analo.AQHandles
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V5_DW.TAQSigLogging_InsertedFor_DataT.AQHandles
                    section.data(5).logicalSrcIdx = 29;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V5_DW.TAQSigLogging_InsertedFor_Dat_j.AQHandles
                    section.data(6).logicalSrcIdx = 30;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V5_DW.TAQSigLogging_InsertedFor_Ana_g.AQHandles
                    section.data(7).logicalSrcIdx = 31;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.sfEvent_m
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.is_c9_Assignment1_V5
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_DW.is_Pace_Rate_Unfixed
                    section.data(2).logicalSrcIdx = 36;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V5_DW.is_c3_Assignment1_V5
                    section.data(3).logicalSrcIdx = 37;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V5_DW.is_finally_c3_Assignment1_V5
                    section.data(4).logicalSrcIdx = 38;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V5_DW.is_PACE
                    section.data(5).logicalSrcIdx = 39;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V5_DW.is_finally_PACE
                    section.data(6).logicalSrcIdx = 40;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V5_DW.is_SENSE
                    section.data(7).logicalSrcIdx = 41;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V5_DW.is_finally_SENSE
                    section.data(8).logicalSrcIdx = 42;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V5_DW.temporalCounter_i1
                    section.data(9).logicalSrcIdx = 43;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V5_DW.is_c7_Assignment1_V5
                    section.data(10).logicalSrcIdx = 44;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V5_DW.is_finally_c7_Assignment1_V5
                    section.data(11).logicalSrcIdx = 45;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.is_active_c9_Assignment1_V5
                    section.data(1).logicalSrcIdx = 46;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V5_DW.temporalCounter_i1_n
                    section.data(2).logicalSrcIdx = 47;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V5_DW.is_active_c3_Assignment1_V5
                    section.data(3).logicalSrcIdx = 48;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V5_DW.tp_Sense_Detect
                    section.data(4).logicalSrcIdx = 49;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V5_DW.tp_Sense_Detected
                    section.data(5).logicalSrcIdx = 50;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V5_DW.tp_Sense_Fail
                    section.data(6).logicalSrcIdx = 51;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V5_DW.Output_Candidate
                    section.data(7).logicalSrcIdx = 52;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V5_DW.Op_Mode
                    section.data(8).logicalSrcIdx = 53;
                    section.data(8).dtTransOffset = 21;

                    ;% Assignment1_V5_DW.is_active_c7_Assignment1_V5
                    section.data(9).logicalSrcIdx = 57;
                    section.data(9).dtTransOffset = 22;

                    ;% Assignment1_V5_DW.temporalCounter_i1_f
                    section.data(10).logicalSrcIdx = 58;
                    section.data(10).dtTransOffset = 23;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V5_DW.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 59;
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


    targMap.checksum0 = 1114394090;
    targMap.checksum1 = 2135641803;
    targMap.checksum2 = 4067916122;
    targMap.checksum3 = 2726320791;

