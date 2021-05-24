# SerialMonitor
Small Serial Monitor written in C++ with Win32 API.


## How to use
```bash
SerialMonitor -b <baudrate> -c <comport> -p <parity> -d <databits> -s <stopbits>
```
To just list the com ports do
```bash
SerialMonitor -L
```

## Arguments
Supported arguments

| Prefix      | Description | 
| ----------- | ----------- |
| -b      | Baudrate       |
| -c   | Com port        |
| -p   | Parity from 0 to 4        |
| -s   | Stopbits        |
| -d   | Databits        |
| -L   | Lists all ports |       

### Parity
The enum is setup like this:

| Value         | Description   |
| --------------| ------------- |
| 0             | None          |
| 1             | Odd           |
| 2             | Even          |
| 3             | Mark          |
| 4             | Space         |

### Stop bits
The enum is setup like this:

| Value         | Description   |
| --------------| ------------- |
| 0             | None          |
| 1             | One           |
| 2             | 1.5           |
