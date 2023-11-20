    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
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
        ;% Auto data (Assignment1_V2_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V2_P.EnumeratedConstant_Value
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% Assignment1_V2_P.DigitalRead_SampleTime
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_P.DigitalRead1_SampleTime
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V2_P.FXOS87006AxesSensor_SampleTime
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V2_P.Constant_Value
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V2_P.Constant_Value_i
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V2_P.Constant1_Value
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V2_P.Constant1_Value_m
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V2_P.Gain2_Gain
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V2_P.Constant4_Value
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment1_V2_P.Constant3_Value
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment1_V2_P.Constant_Value_m
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 10;

                    ;% Assignment1_V2_P.Multiply_Gain
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 11;

                    ;% Assignment1_V2_P.Constant2_Value
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 12;

                    ;% Assignment1_V2_P.Gain_Gain
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 13;

                    ;% Assignment1_V2_P.Gain1_Gain
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
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
        nTotSects     = 6;
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
        ;% Auto data (Assignment1_V2_B)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Assignment1_V2_B.Gain2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_B.VectorConcatenate2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment1_V2_B.VectorConcatenate1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Assignment1_V2_B.Multiply
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% Assignment1_V2_B.smoothed_output
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% Assignment1_V2_B.Smoothed_Output
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% Assignment1_V2_B.Accel_Raw_Magnitude
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% Assignment1_V2_B.PACING_REF_PWM
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V2_B.Motion_State
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V2_B.PACE_SENSE_RESPONSE
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V2_B.PACE_SENSE_CHAMBER
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V2_B.PACE_CHAMBER
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment1_V2_B.VectorConcatenate
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_B.ATR_PACE_CTRL
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment1_V2_B.VENT_PACE_CTRL
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 3;

                    ;% Assignment1_V2_B.PACE_CHARGE_CTRL
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 4;

                    ;% Assignment1_V2_B.PACE_GND_CTRL
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 5;

                    ;% Assignment1_V2_B.ATR_GND_CTRL
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 6;

                    ;% Assignment1_V2_B.VENT_GND_CTRL
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
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
        nTotSects     = 10;
        sectIdxOffset = 6;

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
        ;% Auto data (Assignment1_V2_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.obj_m
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_DW.obj_o
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.obj_p
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_DW.obj_k
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V2_DW.obj_c
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V2_DW.obj_l
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V2_DW.obj_n
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V2_DW.obj_i
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V2_DW.obj_mo
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment1_V2_DW.obj_j
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment1_V2_DW.obj_n2
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.obj_b
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_DW.obj_h
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V2_DW.obj_km
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.rolling_avg
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_DW.init_counter
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V2_DW.Buffer_Internal
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.TAQSigLogging_InsertedFor_Subsy.AQHandles
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_DW.TAQSigLogging_InsertedFor_MATLA.AQHandles
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V2_DW.TAQSigLogging_InsertedFor_MAT_b.AQHandles
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V2_DW.TAQSigLogging_InsertedFor_Sub_k.AQHandles
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.sfEvent
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.is_c3_Assignment1_V2
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_DW.is_finally_c3_Assignment1_V2
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V2_DW.is_PACE
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V2_DW.is_finally_PACE
                    section.data(4).logicalSrcIdx = 26;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment1_V2_DW.is_SENSE
                    section.data(5).logicalSrcIdx = 27;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment1_V2_DW.is_finally_SENSE
                    section.data(6).logicalSrcIdx = 28;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment1_V2_DW.temporalCounter_i1
                    section.data(7).logicalSrcIdx = 29;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.is_active_c3_Assignment1_V2
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_DW.tp_Sense_Detect
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment1_V2_DW.tp_Sense_Detected
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment1_V2_DW.tp_Sense_Fail
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment1_V2_DW.Buffer_Internal_not_empty
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment1_V2_DW.doneDoubleBufferReInit
                    section.data(2).logicalSrcIdx = 36;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
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


    targMap.checksum0 = 3474524650;
    targMap.checksum1 = 3351200685;
    targMap.checksum2 = 3905815002;
    targMap.checksum3 = 1960020723;

