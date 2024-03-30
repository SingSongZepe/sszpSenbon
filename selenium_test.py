from selenium import webdriver

# 创建一个 Chrome 浏览器实例
chrome_path = "C:\\Program Files\\Google\\Chrome\\Application\\chromedriver.exe"
chrome_options = webdriver.ChromeOptions()
chrome_options.binary_location = chrome_path

driver = webdriver.Chrome(options=chrome_options)

# 打开网页
driver.get("https://z-library.se")

# 获取网页标题
title = driver.title
print(title)

# 关闭浏览器
driver.quit()
