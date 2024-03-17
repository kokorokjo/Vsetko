from lumibot.brokers import Alpaca
from lumibot.backtesting import YahooDataBacktesting
from lumibot.strategies.strategy import Strategy
from lumibot.traders import Trader
from datetime import datetime
from alpaca_trade_api import REST
from timedelta import Timedelta
from finbert_utils import estimate_setiment

API_KEY = "PK0HW42X6D5SMI8G7K8B"
API_SECRET = "DE1ZefT2lNJjbqlMBDFhQT2vi0APxj5VZurMVa7V"
BASE_URL = "https://paper-api.alpaca.markets/v2"

ALPACA_CREDS ={
    "API_KEY": API_KEY,
    "API_SECRET": API_SECRET,
    "PAPER": True
}

class MyTrader(Strategy):
    def initialize(self, symbol:str="SPY", cash_at_risk:float=.5):
        self.symbol = symbol
        self.sleeptime ="24H"
        self.last_trade = None
        self.cash_at_risk = cash_at_risk
        self.api = REST(base_url=BASE_URL, key_id=API_KEY, secret_key=API_SECRET)
    
    def positoning_sizing(self):
        cash = self.get_cash()
        last_price = self.get_last_price(self.symbol)
        quantity = round(cash * self.cash_at_risk / last_price, 0)
        return cash, last_price, quantity
    
    def get_dates(self):
        today =self.get_datetime()
        three_days_prior = today - Timedelta(days=3)
        return today.strftime("%Y-%m-%d"), three_days_prior.strftime("%Y-%m-%d")
    
    def get_sentiment(self):
        today, three_days_prior = self.get_dates()
        news =self.api.get_news(symbol = self.symbol, start=three_days_prior, end=today)
        news = [ev.__dict__["_raw"]["headline"] for ev in news]
        probability, sentiment = estimate_setiment(news)
        return probability, sentiment

    def on_trading_iteration(self):
        cash, last_price, quantity = self.positoning_sizing()
        probability, sentiment = self.get_sentiment()


        if cash>last_price:
            if sentiment == "positive" and probability >.999:
                if self.last_trade == "sell":
                    self.sell_all()
                order = self.create_order(
                    self.symbol,
                    quantity,
                    "buy",
                    type="bracket",
                    teake_profit=dict(limit_price=last_price*1.05),
                    stop_loss=dict(stop_price=last_price*.95)
                    )
                self.submit_order(order)
                self.last_trade = "buy"
            elif sentiment == "negative" and probability >.999:
                if self.last_trade == "buy":
                    self.sell_all()
                order = self.create_order(
                    self.symbol,
                    quantity,
                    "sell",
                    type="bracket",
                    teake_profit=dict(limit_price=last_price*.8),
                    stop_loss=dict(stop_price=last_price*1.05)
                    )
                self.submit_order(order)
                self.last_trade = "sell"

start_date = datetime(2021, 1, 1)
end_date = datetime(2024, 1, 1)
broker = Alpaca(ALPACA_CREDS)
strategy = MyTrader(name ="mlstrat", broker=broker, parameters={"symbol":"AAPL", "cash_at_risk":.5})
strategy.backtest(YahooDataBacktesting,start_date, end_date,parameters={"symbol":"SPY", "cash_at_risk":.5})