/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.xiaying.renascence;

public class RenascenceBasic implements RenascenceBasicConstants {
  public static void GP_Set_Lib_Path(String basic_path) {
    RenascenceBasicJNI.GP_Set_Lib_Path(basic_path);
  }

  public static void GP_Set_Stream_Path(String basic_path) {
    RenascenceBasicJNI.GP_Set_Stream_Path(basic_path);
  }

  public static SWIGTYPE_p_GPStream GP_Stream_Create(String filename) {
    long cPtr = RenascenceBasicJNI.GP_Stream_Create(filename);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPStream(cPtr, false);
  }

  public static void GP_Stream_Destroy(SWIGTYPE_p_GPStream s) {
    RenascenceBasicJNI.GP_Stream_Destroy(SWIGTYPE_p_GPStream.getCPtr(s));
  }

  public static SWIGTYPE_p_GPWStream GP_WStream_Create(String filename) {
    long cPtr = RenascenceBasicJNI.GP_WStream_Create(filename);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPWStream(cPtr, false);
  }

  public static void GP_WStream_Destroy(SWIGTYPE_p_GPWStream s) {
    RenascenceBasicJNI.GP_WStream_Destroy(SWIGTYPE_p_GPWStream.getCPtr(s));
  }

  public static SWIGTYPE_p_GPContents GP_Contents_Load(SWIGTYPE_p_AGPProducer producer, SWIGTYPE_p_p_GPStream inputs, String typeNames, int n) {
    long cPtr = RenascenceBasicJNI.GP_Contents_Load(SWIGTYPE_p_AGPProducer.getCPtr(producer), SWIGTYPE_p_p_GPStream.getCPtr(inputs), typeNames, n);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPContents(cPtr, false);
  }

  public static int GP_Contents_Size(SWIGTYPE_p_GPContents contents) {
    return RenascenceBasicJNI.GP_Contents_Size(SWIGTYPE_p_GPContents.getCPtr(contents));
  }

  public static SWIGTYPE_p_void GP_Contents_Get(SWIGTYPE_p_GPContents contents, int n) {
    long cPtr = RenascenceBasicJNI.GP_Contents_Get(SWIGTYPE_p_GPContents.getCPtr(contents), n);
    return (cPtr == 0) ? null : new SWIGTYPE_p_void(cPtr, false);
  }

  public static double GP_Contents_GetDouble(SWIGTYPE_p_GPContents contents, int n) {
    return RenascenceBasicJNI.GP_Contents_GetDouble(SWIGTYPE_p_GPContents.getCPtr(contents), n);
  }

  public static void GP_Contents_SetDouble(SWIGTYPE_p_GPContents contents, double value, int n) {
    RenascenceBasicJNI.GP_Contents_SetDouble(SWIGTYPE_p_GPContents.getCPtr(contents), value, n);
  }

  public static SWIGTYPE_p_GPContents GP_Contents_CreateDouble(double value) {
    long cPtr = RenascenceBasicJNI.GP_Contents_CreateDouble(value);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPContents(cPtr, false);
  }

  public static SWIGTYPE_p_GPContents GP_Contents_CreateString(String value) {
    long cPtr = RenascenceBasicJNI.GP_Contents_CreateString(value);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPContents(cPtr, false);
  }

  public static void GP_Contents_Save(SWIGTYPE_p_GPContents content, SWIGTYPE_p_GPWStream outputs, int n) {
    RenascenceBasicJNI.GP_Contents_Save(SWIGTYPE_p_GPContents.getCPtr(content), SWIGTYPE_p_GPWStream.getCPtr(outputs), n);
  }

  public static void GP_Contents_Destroy(SWIGTYPE_p_GPContents content) {
    RenascenceBasicJNI.GP_Contents_Destroy(SWIGTYPE_p_GPContents.getCPtr(content));
  }

  public static SWIGTYPE_p_GPContents GP_Contents_CreateCollector() {
    long cPtr = RenascenceBasicJNI.GP_Contents_CreateCollector();
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPContents(cPtr, false);
  }

  public static void GP_Contents_Collect(SWIGTYPE_p_GPContents Collector, SWIGTYPE_p_GPContents B, int n) {
    RenascenceBasicJNI.GP_Contents_Collect(SWIGTYPE_p_GPContents.getCPtr(Collector), SWIGTYPE_p_GPContents.getCPtr(B), n);
  }

  public static SWIGTYPE_p_AGPProducer GP_Producer_Create(SWIGTYPE_p_p_GPStream metaStream, SWIGTYPE_p_p_IFunctionTable table, int n, int type) {
    long cPtr = RenascenceBasicJNI.GP_Producer_Create(SWIGTYPE_p_p_GPStream.getCPtr(metaStream), SWIGTYPE_p_p_IFunctionTable.getCPtr(table), n, type);
    return (cPtr == 0) ? null : new SWIGTYPE_p_AGPProducer(cPtr, false);
  }

  public static void GP_Producer_Destroy(SWIGTYPE_p_AGPProducer p) {
    RenascenceBasicJNI.GP_Producer_Destroy(SWIGTYPE_p_AGPProducer.getCPtr(p));
  }

  public static SWIGTYPE_p_IGPAutoDefFunction GP_Function_Create_ByType(SWIGTYPE_p_AGPProducer p, String outputTypes, String inputTypes, GPOptimizorInfo pInfo) {
    long cPtr = RenascenceBasicJNI.GP_Function_Create_ByType(SWIGTYPE_p_AGPProducer.getCPtr(p), outputTypes, inputTypes, GPOptimizorInfo.getCPtr(pInfo), pInfo);
    return (cPtr == 0) ? null : new SWIGTYPE_p_IGPAutoDefFunction(cPtr, false);
  }

  public static SWIGTYPE_p_IGPAutoDefFunction GP_Function_Create_ByFormula(SWIGTYPE_p_AGPProducer p, String formula, String inputType, GPOptimizorInfo pInfo) {
    long cPtr = RenascenceBasicJNI.GP_Function_Create_ByFormula(SWIGTYPE_p_AGPProducer.getCPtr(p), formula, inputType, GPOptimizorInfo.getCPtr(pInfo), pInfo);
    return (cPtr == 0) ? null : new SWIGTYPE_p_IGPAutoDefFunction(cPtr, false);
  }

  public static SWIGTYPE_p_GPContents GP_Function_Run(SWIGTYPE_p_IGPAutoDefFunction f, SWIGTYPE_p_GPContents input) {
    long cPtr = RenascenceBasicJNI.GP_Function_Run(SWIGTYPE_p_IGPAutoDefFunction.getCPtr(f), SWIGTYPE_p_GPContents.getCPtr(input));
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPContents(cPtr, false);
  }

  public static void GP_Function_Destroy(SWIGTYPE_p_IGPAutoDefFunction f) {
    RenascenceBasicJNI.GP_Function_Destroy(SWIGTYPE_p_IGPAutoDefFunction.getCPtr(f));
  }

  public static SWIGTYPE_p_IGPAutoDefFunction GP_Function_Create_ByStream(SWIGTYPE_p_AGPProducer p, SWIGTYPE_p_GPStream xmlFile) {
    long cPtr = RenascenceBasicJNI.GP_Function_Create_ByStream(SWIGTYPE_p_AGPProducer.getCPtr(p), SWIGTYPE_p_GPStream.getCPtr(xmlFile));
    return (cPtr == 0) ? null : new SWIGTYPE_p_IGPAutoDefFunction(cPtr, false);
  }

  public static void GP_Function_Save(SWIGTYPE_p_IGPAutoDefFunction f, SWIGTYPE_p_GPWStream output) {
    RenascenceBasicJNI.GP_Function_Save(SWIGTYPE_p_IGPAutoDefFunction.getCPtr(f), SWIGTYPE_p_GPWStream.getCPtr(output));
  }

  public static void GP_Function_Optimize(SWIGTYPE_p_IGPAutoDefFunction f, GPOptimizorInfo pInfo) {
    RenascenceBasicJNI.GP_Function_Optimize(SWIGTYPE_p_IGPAutoDefFunction.getCPtr(f), GPOptimizorInfo.getCPtr(pInfo), pInfo);
  }

  public static SWIGTYPE_p_p_GPStream GP_Streams_Malloc(int n) {
    long cPtr = RenascenceBasicJNI.GP_Streams_Malloc(n);
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_GPStream(cPtr, false);
  }

  public static void GP_Streams_Free(SWIGTYPE_p_p_GPStream streams) {
    RenascenceBasicJNI.GP_Streams_Free(SWIGTYPE_p_p_GPStream.getCPtr(streams));
  }

  public static SWIGTYPE_p_GPStream GP_Streams_Get(SWIGTYPE_p_p_GPStream streams, int n) {
    long cPtr = RenascenceBasicJNI.GP_Streams_Get(SWIGTYPE_p_p_GPStream.getCPtr(streams), n);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPStream(cPtr, false);
  }

  public static void GP_Streams_Set(SWIGTYPE_p_p_GPStream streams, SWIGTYPE_p_GPStream contents, int n) {
    RenascenceBasicJNI.GP_Streams_Set(SWIGTYPE_p_p_GPStream.getCPtr(streams), SWIGTYPE_p_GPStream.getCPtr(contents), n);
  }

  public static int GP_Strings_Number(SWIGTYPE_p_AGPStrings strings) {
    return RenascenceBasicJNI.GP_Strings_Number(SWIGTYPE_p_AGPStrings.getCPtr(strings));
  }

  public static String GP_Strings_Get(SWIGTYPE_p_AGPStrings strings, int n) {
    return RenascenceBasicJNI.GP_Strings_Get(SWIGTYPE_p_AGPStrings.getCPtr(strings), n);
  }

  public static void GP_Strings_Free(SWIGTYPE_p_AGPStrings strings) {
    RenascenceBasicJNI.GP_Strings_Free(SWIGTYPE_p_AGPStrings.getCPtr(strings));
  }

  public static SWIGTYPE_p_AGPStrings GP_Function_GetFormula(SWIGTYPE_p_IGPAutoDefFunction f, String adfName) {
    long cPtr = RenascenceBasicJNI.GP_Function_GetFormula(SWIGTYPE_p_IGPAutoDefFunction.getCPtr(f), adfName);
    return (cPtr == 0) ? null : new SWIGTYPE_p_AGPStrings(cPtr, false);
  }

  public static SWIGTYPE_p_AGPStrings GP_Function_GetParameters(SWIGTYPE_p_IGPAutoDefFunction f) {
    long cPtr = RenascenceBasicJNI.GP_Function_GetParameters(SWIGTYPE_p_IGPAutoDefFunction.getCPtr(f));
    return (cPtr == 0) ? null : new SWIGTYPE_p_AGPStrings(cPtr, false);
  }

  public static void GP_Function_MapParameters(SWIGTYPE_p_IGPAutoDefFunction f, String parameters) {
    RenascenceBasicJNI.GP_Function_MapParameters(SWIGTYPE_p_IGPAutoDefFunction.getCPtr(f), parameters);
  }

  public static SWIGTYPE_p_AGPStrings GP_Producer_ListFunctions(SWIGTYPE_p_AGPProducer producer) {
    long cPtr = RenascenceBasicJNI.GP_Producer_ListFunctions(SWIGTYPE_p_AGPProducer.getCPtr(producer));
    return (cPtr == 0) ? null : new SWIGTYPE_p_AGPStrings(cPtr, false);
  }

  public static SWIGTYPE_p_AGPStrings GP_Producer_ListTypes(SWIGTYPE_p_AGPProducer producer) {
    long cPtr = RenascenceBasicJNI.GP_Producer_ListTypes(SWIGTYPE_p_AGPProducer.getCPtr(producer));
    return (cPtr == 0) ? null : new SWIGTYPE_p_AGPStrings(cPtr, false);
  }

  public static SWIGTYPE_p_AGPStrings GP_Contents_Types(SWIGTYPE_p_GPContents contents) {
    long cPtr = RenascenceBasicJNI.GP_Contents_Types(SWIGTYPE_p_GPContents.getCPtr(contents));
    return (cPtr == 0) ? null : new SWIGTYPE_p_AGPStrings(cPtr, false);
  }

  public static GPOptimizorInfo GP_OptimzorInfo_CreateTemplate(int depth, int maxtimes, int type, SWIGTYPE_p_GPContents pInput, SWIGTYPE_p_GPWStream bestCache, SWIGTYPE_p_IGPAutoDefFunction pPostFunction, SWIGTYPE_p_GPContents pPostExtraInput) {
    long cPtr = RenascenceBasicJNI.GP_OptimzorInfo_CreateTemplate(depth, maxtimes, type, SWIGTYPE_p_GPContents.getCPtr(pInput), SWIGTYPE_p_GPWStream.getCPtr(bestCache), SWIGTYPE_p_IGPAutoDefFunction.getCPtr(pPostFunction), SWIGTYPE_p_GPContents.getCPtr(pPostExtraInput));
    return (cPtr == 0) ? null : new GPOptimizorInfo(cPtr, false);
  }

  public static void GP_OptimzorInfo_FreeTemplate(GPOptimizorInfo pInfo) {
    RenascenceBasicJNI.GP_OptimzorInfo_FreeTemplate(GPOptimizorInfo.getCPtr(pInfo), pInfo);
  }

  public static double GP_OptimzorInfo_TemplateGetBestValue(GPOptimizorInfo pInfo) {
    return RenascenceBasicJNI.GP_OptimzorInfo_TemplateGetBestValue(GPOptimizorInfo.getCPtr(pInfo), pInfo);
  }

  public static SWIGTYPE_p_AGPPiecesProducer GP_PiecesProducer_Create(SWIGTYPE_p_AGPProducer producer, SWIGTYPE_p_p_GPStream piecesLibMeta, SWIGTYPE_p_p_IFunctionTable piecesLibTable, int libNumber, SWIGTYPE_p_p_GPStream mapReduceMeta, int mapReduceMetaNumber) {
    long cPtr = RenascenceBasicJNI.GP_PiecesProducer_Create(SWIGTYPE_p_AGPProducer.getCPtr(producer), SWIGTYPE_p_p_GPStream.getCPtr(piecesLibMeta), SWIGTYPE_p_p_IFunctionTable.getCPtr(piecesLibTable), libNumber, SWIGTYPE_p_p_GPStream.getCPtr(mapReduceMeta), mapReduceMetaNumber);
    return (cPtr == 0) ? null : new SWIGTYPE_p_AGPPiecesProducer(cPtr, false);
  }

  public static void GP_PiecesProducer_Destroy(SWIGTYPE_p_AGPPiecesProducer producer) {
    RenascenceBasicJNI.GP_PiecesProducer_Destroy(SWIGTYPE_p_AGPPiecesProducer.getCPtr(producer));
  }

  public static SWIGTYPE_p_AGPStrings GP_PiecesProducer_ListType(SWIGTYPE_p_AGPPiecesProducer producer) {
    long cPtr = RenascenceBasicJNI.GP_PiecesProducer_ListType(SWIGTYPE_p_AGPPiecesProducer.getCPtr(producer));
    return (cPtr == 0) ? null : new SWIGTYPE_p_AGPStrings(cPtr, false);
  }

  public static SWIGTYPE_p_GPPiecesFunction GP_PiecesFunction_Create(SWIGTYPE_p_AGPPiecesProducer producer, String formula, String inputType, String type) {
    long cPtr = RenascenceBasicJNI.GP_PiecesFunction_Create(SWIGTYPE_p_AGPPiecesProducer.getCPtr(producer), formula, inputType, type);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPPiecesFunction(cPtr, false);
  }

  public static SWIGTYPE_p_GPPieces GP_PiecesFunction_Run(SWIGTYPE_p_GPPiecesFunction piecesFunction, SWIGTYPE_p_p_GPPieces inputs, int inputNumber) {
    long cPtr = RenascenceBasicJNI.GP_PiecesFunction_Run(SWIGTYPE_p_GPPiecesFunction.getCPtr(piecesFunction), SWIGTYPE_p_p_GPPieces.getCPtr(inputs), inputNumber);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPPieces(cPtr, false);
  }

  public static void GP_PiecesFunction_Destroy(SWIGTYPE_p_GPPiecesFunction pieceFunction) {
    RenascenceBasicJNI.GP_PiecesFunction_Destroy(SWIGTYPE_p_GPPiecesFunction.getCPtr(pieceFunction));
  }

  public static SWIGTYPE_p_GPPieces GP_Pieces_Load(SWIGTYPE_p_AGPPiecesProducer producer, String type, String path, String description) {
    long cPtr = RenascenceBasicJNI.GP_Pieces_Load(SWIGTYPE_p_AGPPiecesProducer.getCPtr(producer), type, path, description);
    return (cPtr == 0) ? null : new SWIGTYPE_p_GPPieces(cPtr, false);
  }

  public static void GP_Pieces_Save(SWIGTYPE_p_GPPieces pieces, String path, String description) {
    RenascenceBasicJNI.GP_Pieces_Save(SWIGTYPE_p_GPPieces.getCPtr(pieces), path, description);
  }

  public static void GP_Pieces_Destroy(SWIGTYPE_p_GPPieces pieces) {
    RenascenceBasicJNI.GP_Pieces_Destroy(SWIGTYPE_p_GPPieces.getCPtr(pieces));
  }

}
