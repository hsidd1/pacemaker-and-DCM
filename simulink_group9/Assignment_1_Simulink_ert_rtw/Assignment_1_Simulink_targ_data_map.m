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
        ;% Auto data (Assignment_1_Simulink_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_P.EnumeratedConstant_Value
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_P.DigitalRead_SampleTime
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_P.DigitalRead1_SampleTime
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment_1_Simulink_P.Constant1_Value
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment_1_Simulink_P.Gain2_Gain
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment_1_Simulink_P.Constant4_Value
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment_1_Simulink_P.Constant3_Value
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment_1_Simulink_P.Constant_Value
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment_1_Simulink_P.Multiply_Gain
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment_1_Simulink_P.Constant2_Value
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% Assignment_1_Simulink_P.Gain_Gain
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

                    ;% Assignment_1_Simulink_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 10;

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
        nTotSects     = 5;
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
        ;% Auto data (Assignment_1_Simulink_B)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_B.Gain2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_B.VectorConcatenate2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment_1_Simulink_B.VectorConcatenate1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Assignment_1_Simulink_B.Multiply
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% Assignment_1_Simulink_B.PACING_REF_PWM
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_B.PACE_SENSE_RESPONSE
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_B.PACE_SENSE_CHAMBER
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_B.PACE_CHAMBER
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_B.VectorConcatenate
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_B.ATR_PACE_CTRL
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 2;

                    ;% Assignment_1_Simulink_B.VENT_PACE_CTRL
                    section.data(3).logicalSrcIdx = 10;
                    section.data(3).dtTransOffset = 3;

                    ;% Assignment_1_Simulink_B.PACE_CHARGE_CTRL
                    section.data(4).logicalSrcIdx = 11;
                    section.data(4).dtTransOffset = 4;

                    ;% Assignment_1_Simulink_B.PACE_GND_CTRL
                    section.data(5).logicalSrcIdx = 12;
                    section.data(5).dtTransOffset = 5;

                    ;% Assignment_1_Simulink_B.ATR_GND_CTRL
                    section.data(6).logicalSrcIdx = 13;
                    section.data(6).dtTransOffset = 6;

                    ;% Assignment_1_Simulink_B.VENT_GND_CTRL
                    section.data(7).logicalSrcIdx = 14;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
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
        nTotSects     = 7;
        sectIdxOffset = 5;

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
        ;% Auto data (Assignment_1_Simulink_DW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_DW.obj_b
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_DW.obj_i
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_DW.obj_m
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment_1_Simulink_DW.obj_a
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment_1_Simulink_DW.obj_n
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment_1_Simulink_DW.obj_j
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment_1_Simulink_DW.obj_n2
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment_1_Simulink_DW.obj_bo
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 6;

                    ;% Assignment_1_Simulink_DW.obj_h
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 7;

                    ;% Assignment_1_Simulink_DW.obj_g
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_DW.obj_mz
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_DW.obj_iw
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment_1_Simulink_DW.obj_bn
                    section.data(3).logicalSrcIdx = 13;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_DW.TAQSigLogging_InsertedFor_MATLA.AQHandles
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_DW.TAQSigLogging_InsertedFor_MAT_p.AQHandles
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment_1_Simulink_DW.TAQSigLogging_InsertedFor_MA_pq.AQHandles
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment_1_Simulink_DW.TAQSigLogging_InsertedFor_Vecto.AQHandles
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_DW.sfEvent
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_DW.is_c3_Assignment_1_Simulink
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_DW.is_finally_c3_Assignment_1_Simu
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment_1_Simulink_DW.is_PACE
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment_1_Simulink_DW.is_finally_PACE
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 3;

                    ;% Assignment_1_Simulink_DW.is_SENSE
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 4;

                    ;% Assignment_1_Simulink_DW.is_finally_SENSE
                    section.data(6).logicalSrcIdx = 24;
                    section.data(6).dtTransOffset = 5;

                    ;% Assignment_1_Simulink_DW.temporalCounter_i1
                    section.data(7).logicalSrcIdx = 25;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Assignment_1_Simulink_DW.is_active_c3_Assignment_1_Simul
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

                    ;% Assignment_1_Simulink_DW.tp_Sense_Detect
                    section.data(2).logicalSrcIdx = 27;
                    section.data(2).dtTransOffset = 1;

                    ;% Assignment_1_Simulink_DW.tp_Sense_Detected
                    section.data(3).logicalSrcIdx = 28;
                    section.data(3).dtTransOffset = 2;

                    ;% Assignment_1_Simulink_DW.tp_Sense_Fail
                    section.data(4).logicalSrcIdx = 29;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
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


    targMap.checksum0 = 2095610052;
    targMap.checksum1 = 2621167969;
    targMap.checksum2 = 701678346;
    targMap.checksum3 = 1025897167;

