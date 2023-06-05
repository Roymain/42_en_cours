import time as time
import datetime


secs = time.time()
science = "{:.2e}".format(secs)

print("Seconds since", time.strftime("%buary %d, %Y:", time.gmtime(0)), "{:,.4f}".format(secs), "or" ,  "{:.2e}".format(secs), "in scientific notation")
res = datetime.date.today()
month = res.month
print(res.strftime("%b"), res.day, res.year)