// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#define EXWORLDLOG(x) UE_LOG(LogTemp,Warning,TEXT(x))
//SW for Warning
#define EXWORLDLOG_SW(x,y) UE_LOG(LogTemp,Warning,TEXT(x "%s"), *y)
//SE for Error
#define EXWORLDLOG_SE(x,y) UE_LOG(LogTemp,Error,TEXT(x "%s"), *y)
// Int Log for Warning
#define EXWORLDLOG_IW(x,y) UE_LOG(LogTemp,Warning,TEXT(x "%d"), y)


