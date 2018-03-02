
//  KVC-DictionaryToModel
//
//  Created by fangyukui on 2018/3/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>
// 字典转模型
@interface NSObject (Model)

+ (instancetype)modelWithDict:(NSDictionary *)dict;

@end
