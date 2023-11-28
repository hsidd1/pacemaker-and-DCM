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
        ;% Auto data (Assignment1_V4_P)
        ;%
            section.nData     = 29;
            section.data(29)  = dumData; %prealloc

                    ;% Assignment1_V4_P.FXOS87006AxesSensor_SampleTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_P.AnalogInput_SampleTime
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V4_P.AnalogInput1_SampleTime
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V4_P.DigitalRead_SampleTime
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V4_P.DigitalRead1_SampleTime
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V4_P.Constant10_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V4_P.Constant_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V4_P.Constant5_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V4_P.Constant9_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V4_P.Constant1_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V4_P.Constant3_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V4_P.Constant2_Value
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% Assignment1_V4_P.Constant4_Value
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% Assignment1_V4_P.Constant6_Value
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% Assignment1_V4_P.Constant7_Value
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% Assignment1_V4_P.Constant8_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% Assignment1_V4_P.Constant2_Value_i
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% Assignment1_V4_P.Constant_Value_e
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% Assignment1_V4_P.Constant1_Value_i
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 20;

                    ;% Assignment1_V4_P.Gain2_Gain
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 22;

                    ;% Assignment1_V4_P.Constant_Value_n
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 23;

                    ;% Assignment1_V4_P.Gain_Gain
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 24;

                    ;% Assignment1_V4_P.Multiply2_Gain
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 25;

                    ;% Assignment1_V4_P.Gain4_Gain
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 26;

                    ;% Assignment1_V4_P.Gain5_Gain
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 27;

                    ;% Assignment1_V4_P.Multiply_Gain
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 28;

                    ;% Assignment1_V4_P.Multiply1_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 29;

                    ;% Assignment1_V4_P.Gain1_Gain
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 30;

                    ;% Assignment1_V4_P.Gain_Gain_c
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 31;

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
        nTotSects     = 7;
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
        ;% Auto data (Assignment1_V4_B)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Assignment1_V4_B.VectorConcatenate1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_B.Gain2
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 15;

                    ;% Assignment1_V4_B.VectorConcatenate2
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 17;

                    ;% Assignment1_V4_B.VectorConcatenate1_a
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% Assignment1_V4_B.Constant2
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_B.Constant
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V4_B.Gain
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 4;

                    ;% Assignment1_V4_B.Multiply2
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 5;

                    ;% Assignment1_V4_B.Gain4
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 6;

                    ;% Assignment1_V4_B.Gain5
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 7;

                    ;% Assignment1_V4_B.Multiply
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 8;

                    ;% Assignment1_V4_B.Multiply1
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 9;

                    ;% Assignment1_V4_B.sense_timeout_threshold
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 10;

                    ;% Assignment1_V4_B.tgt
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 11;

                    ;% Assignment1_V4_B.dif
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 12;

                    ;% Assignment1_V4_B.PACING_REF_PWM
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 13;

                    ;% Assignment1_V4_B.red
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 14;

                    ;% Assignment1_V4_B.blue
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 15;

                    ;% Assignment1_V4_B.green
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 16;

                    ;% Assignment1_V4_B.Params_Arr
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 17;

                    ;% Assignment1_V4_B.Motion_State
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 32;

                    ;% Assignment1_V4_B.smoothed_output
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 33;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V4_B.PACE_SENSE_RESPONSE
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V4_B.PACE_SENSE_CHAMBER
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V4_B.PACE_RATE_MODE
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V4_B.PACE_CHAMBER
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment1_V4_B.VectorConcatenate
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_B.ATR_PACE_CTRL
                    section.data(2).logicalSrcIdx = 27;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment1_V4_B.VENT_PACE_CTRL
                    section.data(3).logicalSrcIdx = 28;
                    section.data(3).dtTransOffset = 3;

                    ;% Assignment1_V4_B.PACE_CHARGE_CTRL
                    section.data(4).logicalSrcIdx = 29;
                    section.data(4).dtTransOffset = 4;

                    ;% Assignment1_V4_B.PACE_GND_CTRL
                    section.data(5).logicalSrcIdx = 30;
                    section.data(5).dtTransOffset = 5;

                    ;% Assignment1_V4_B.ATR_GND_CTRL
                    section.data(6).logicalSrcIdx = 31;
                    section.data(6).dtTransOffset = 6;

                    ;% Assignment1_V4_B.VENT_GND_CTRL
                    section.data(7).logicalSrcIdx = 32;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
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
        sectIdxOffset = 7;

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
        ;% Auto data (Assignment1_V4_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.obj_m
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_DW.obj_i
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.obj_ir
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_DW.obj_m4
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.obj_o
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_DW.obj_b
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V4_DW.obj_d
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V4_DW.obj_a
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V4_DW.obj_o1
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V4_DW.obj_e
                    section.data(6).logicalSrcIdx = 10;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V4_DW.obj_l
                    section.data(7).logicalSrcIdx = 11;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V4_DW.obj_f
                    section.data(8).logicalSrcIdx = 12;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V4_DW.obj_n
                    section.data(9).logicalSrcIdx = 13;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V4_DW.obj_fj
                    section.data(10).logicalSrcIdx = 14;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V4_DW.obj_p
                    section.data(11).logicalSrcIdx = 15;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V4_DW.obj_ia
                    section.data(12).logicalSrcIdx = 16;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.obj_j
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_DW.obj_dx
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V4_DW.obj_lo
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.resp_fac_decay
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_DW.resp_fac_grow
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 3;

                    ;% Assignment1_V4_DW.Output_Candidate
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 6;

                    ;% Assignment1_V4_DW.rolling_avg
                    section.data(4).logicalSrcIdx = 24;
                    section.data(4).dtTransOffset = 21;

                    ;% Assignment1_V4_DW.init_counter
                    section.data(5).logicalSrcIdx = 25;
                    section.data(5).dtTransOffset = 22;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.TAQSigLogging_InsertedFor_RATE_.AQHandles
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_DW.TAQSigLogging_InsertedFor_RAT_c.AQHandles
                    section.data(2).logicalSrcIdx = 27;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V4_DW.TAQSigLogging_InsertedFor_RAT_b.AQHandles
                    section.data(3).logicalSrcIdx = 28;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V4_DW.TAQSigLogging_InsertedFor_Motio.AQHandles
                    section.data(4).logicalSrcIdx = 29;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V4_DW.TAQSigLogging_InsertedFor_MATLA.AQHandles
                    section.data(5).logicalSrcIdx = 30;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V4_DW.TAQSigLogging_InsertedFor_Mot_i.AQHandles
                    section.data(6).logicalSrcIdx = 31;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V4_DW.TAQSigLogging_InsertedFor_MAT_b.AQHandles
                    section.data(7).logicalSrcIdx = 32;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.sfEvent_a
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.is_c9_Assignment1_V4
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_DW.is_c3_Assignment1_V4
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V4_DW.is_finally_c3_Assignment1_V4
                    section.data(3).logicalSrcIdx = 38;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V4_DW.is_PACE
                    section.data(4).logicalSrcIdx = 39;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V4_DW.is_finally_PACE
                    section.data(5).logicalSrcIdx = 40;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V4_DW.is_SENSE
                    section.data(6).logicalSrcIdx = 41;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V4_DW.is_finally_SENSE
                    section.data(7).logicalSrcIdx = 42;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V4_DW.temporalCounter_i1
                    section.data(8).logicalSrcIdx = 43;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V4_DW.is_c7_Assignment1_V4
                    section.data(9).logicalSrcIdx = 44;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V4_DW.is_finally_c7_Assignment1_V4
                    section.data(10).logicalSrcIdx = 45;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.is_active_c9_Assignment1_V4
                    section.data(1).logicalSrcIdx = 47;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V4_DW.temporalCounter_i1_n
                    section.data(2).logicalSrcIdx = 48;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V4_DW.is_active_c3_Assignment1_V4
                    section.data(3).logicalSrcIdx = 49;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V4_DW.tp_Sense_Detect
                    section.data(4).logicalSrcIdx = 50;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V4_DW.tp_Sense_Detected
                    section.data(5).logicalSrcIdx = 51;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V4_DW.tp_Sense_Fail
                    section.data(6).logicalSrcIdx = 52;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V4_DW.is_active_c7_Assignment1_V4
                    section.data(7).logicalSrcIdx = 55;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V4_DW.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 56;
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


    targMap.checksum0 = 3127486407;
    targMap.checksum1 = 2707041077;
    targMap.checksum2 = 2916617302;
    targMap.checksum3 = 900484409;

