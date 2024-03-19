import pandas as pd

df = pd.read_csv('/home/martin/Desktop/Programy/Python/baseData/assignment-database.csv')


print(df) 

print("Cell with NaN values:")
print(df[df.isnull().any(axis=1)])

print("Cell with blank space:")
df['Product Name'] = df['Product Name'].astype(str)  
mask = df['Product Name'].str.startswith(' ')  
result = df[mask]  
print(result)

new_df = df.dropna()

#To find cells with incorrect data types in the Price column, I'm using new dataframe without NaN values
print("Cells with incorrect data types in the Price column:")
df['Price'] = pd.to_numeric(df['Price'], errors='coerce')
incorrect_prices = df[pd.isna(df['Price'])]
print(incorrect_prices)

new_df = df.dropna(subset=['Price'])

print("Duplicate Product ID entries:")
duplicate_product_ids = df[df.duplicated(subset='Product ID', keep=False)]
print(duplicate_product_ids)

new_df.drop_duplicates(subset='Product ID', keep='first', inplace=True)
new_df.to_csv('/home/martin/Desktop/Programy/Python/baseData/assignment-database-cleaned.csv', index=False)