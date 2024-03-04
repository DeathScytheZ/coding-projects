def years(Num_Of_Days):
    num_of_years = Num_Of_Days // 365
    num_of_months = (Num_Of_Days % 365) // 30
    num_of_weeks = ((Num_Of_Days % 365) % 30) // 7
    num_of_days = ((Num_Of_Days % 365) % 30) % 7
    print(num_of_years, "year(s)")
    print(num_of_months, "month(s)")
    print(num_of_weeks, "week(s)")
    print(num_of_days, "day(s)")

Num_Of_Days = int(input("How many days? "))
years(Num_Of_Days)
