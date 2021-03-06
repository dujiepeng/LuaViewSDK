//
//  LVPkg.h
//  LVSDK
//
//  Created by dongxicheng on 5/4/15.
//  Copyright (c) 2015 dongxicheng. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LUAVIEW_ROOT_PATH  @"LUAVIEW"
#define LUAVIEW_VERSION   "3.0.0"

#define LV_PKGINFO_PROPERTY_URL      @"url"
#define LV_PKGINFO_PROPERTY_TIME     @"time"
#define LV_PKGINFO_SHA256            @"sha256"

#import "LVRSA.h"

@class LVPackage;

typedef void(^LVDownloadCallback)(NSDictionary* info, NSString* error);

@interface LVPkgManager : NSObject

+(BOOL) unpackageFile:(NSString*) fileName packageName:(NSString*) packageName  checkTime:(BOOL) checkTime;

// 返回值说明   0:本地和线上版本一样;   1:即将去下载;   -1:错误
+(NSInteger) downLoadPackage:(NSString*)packageName withInfo:(NSDictionary*) info;
// 返回值说明   0:本地和线上版本一样;   1:即将去下载;   -1:错误
+(NSInteger) downLoadPackage:(NSString*)packageName withInfo:(NSDictionary*) info callback:(LVDownloadCallback) callback;

+(NSData*) readLuaFile:(NSString*) fileName package:(LVPackage*) package rsa:(LVRSA*) rsa;

+(NSString*) timeOfPackage:(LVPackage*)package;
+(BOOL) wirteTimeForPackage:(LVPackage*)packageName time:(NSString*) time;

+(NSString*) timeOfLocalPackage:(LVPackage*)package ;
+(BOOL) wirteTimeForLocalPackage:(LVPackage*)package time:(NSString*) time;

// 返回值说明   0:本地和线上版本一样;   -1:错误或者不相等
+(int) compareLocalInfoOfPackage:(NSString*)name withServerInfo:(NSDictionary*) info;

//清理所有LuaView相关文件
+(void) clearCachesPath;

@end
