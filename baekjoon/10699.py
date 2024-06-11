import datetime

zoneinfo = datetime.timezone(datetime.timedelta(hours=9), "KST")
x = datetime.datetime.now(tz=zoneinfo)


print(x.strftime("%Y-%m-%d"))