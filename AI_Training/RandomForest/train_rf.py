

import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import cross_val_score, StratifiedKFold

data = pd.read_csv("irrigation.csv")

data = data.drop(columns=["CropDays"],axis=1)


le = LabelEncoder()
data['CropType_Encoded'] = le.fit_transform(data['CropType'])
print("--- BẢNG TRA CỨU MÃ CÂY---")
for i, item in enumerate(le.classes_):
    print(f"ID: {i}  -->  Tên: {item}")
print("-------------------------------------------")

X = data[['CropType_Encoded', 'SoilMoisture', 'temperature', 'Humidity']]
y = data['Irrigation']

def parameter_optimation():
    param = {
        'n_estimators': [i for i in range(1, 21)],

        'max_depth': [i for i in range(1, 21)],
    }
    max_scores = None
    max_score = 0
    max_n = 0
    max_m = 0
    for n in param['n_estimators']:
        for m in param['max_depth']:
            skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)
            model = RandomForestClassifier(n_estimators=n, max_depth=m, random_state=42)
            scores = cross_val_score(model, X, y, cv=skf, scoring='accuracy', n_jobs=-1)
            scorce = scores.mean()*100
            if score > max_score:
                max_scores = scores
                max_score = score
                max_n = n
                max_m = m
    print(scores)
    print(f"max_score: {max_score}, n_estimators: {max_n}, max_depth: {max_m}")
    return max_n, max_m

estimators, depth = parameter_optimation()
model = RandomForestClassifier(n_estimators=estimators, max_depth=depth, random_state=42)
model.fit(X.values, y.values)


code_c = m2c.export_to_c(model)


content_c = f"""#include <string.h>
#include "model.h"

{code_c}
"""

with open("model.c", "w") as f:
    f.write(content_c)

content_h = """#ifndef MODEL_H
#define MODEL_H

#ifdef __cplusplus
extern "C" {
#endif

double score(double * input);

#ifdef __cplusplus
}
#endif

#endif
"""
with open("model.h", "w") as f:

    f.write(content_h)

print("ĐÃ XONG! Python đã tạo ra 2 file: 'model.c' và 'model.h'")



