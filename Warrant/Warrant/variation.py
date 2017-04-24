from pylab import *
import pandas as pd




# plot price w.r.t vol
def plot_vol():
    data_vol = pd.read_csv("vol_para.txt")
    data_vol["call_value"]=data_vol.withoutcall - data_vol.withcall
    plot(data_vol.vol,data_vol.withcall,linewidth=2.5,\
            label="with call right")
    # plot(data_vol.vol,data_vol.withoutcall,linewidth=2.5,\
    #         label="without call right")
    legend(loc="best")
    xlabel("volatility of stock 1")
    ylabel("warrant price")
    title("variation of warrant's price w.r.t volatility of stock 1")
    show()

# plot price w.r.t rate
def plot_rate():
    data_rate = pd.read_csv("rate_para.txt")
    data_rate["call_value"] = data_rate.withoutcall \
                              - data_rate.withcall
    plot(data_rate.rate,data_rate.withcall,linewidth=2.5,label="with call right")
    plot(data_rate.rate,data_rate.withoutcall,linewidth=2.5,label="without call right")
    legend(loc="best")
    xlabel("level of the riskless interest rate")
    ylabel("warrant price")
    title("variation of warrant's price w.r.t interest rate")
    show()

# plot price w.r.t correlation
def plot_rou(num="01"):
    data_corr = pd.read_csv("rou_para_{}.txt".format(num))
    data_corr["call_value"]=data_corr.withoutcall - data_corr.withcall
    plot(data_corr.rou,data_corr.withcall,\
            linewidth=2.5,label="with call right")
    # plot(data_corr.rou,data_corr.withoutcall,\
    #         linewidth=2.5,label="without call right")
    legend(loc="best")
    xlabel("correlation coefficient")
    ylabel("warrant price")
    title("variation of warrant's price w.r.t correlation coefficient")
    # show()

# plot call right value
def plot_call(num='00'):
    data_vol = pd.read_csv("vol_para.txt")
    data_vol["call_value"]=data_vol.withoutcall - data_vol.withcall
    data_rate = pd.read_csv("rate_para.txt")
    data_rate["call_value"] = data_rate.withoutcall \
                              - data_rate.withcall
    plot(data_rate.rate,data_rate.call_value)
    xlabel("level of the riskless interest rate")
    ylabel("call right value")
    show()
    plot(data_vol.vol,data_vol.call_value)
    xlabel("volatility of stock 1")
    ylabel("call right value")
    show()
    data_corr = pd.read_csv("rou_para_{}.txt".format(num))
    data_corr["call_value"]=data_corr.withoutcall - data_corr.withcall
    plot(data_corr.rou,data_corr.call_value)
    xlabel("correlation coefficient")
    ylabel("call right value")
    # show()
