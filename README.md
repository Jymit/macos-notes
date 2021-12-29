# macos-notes

/System/Library/PrivateFrameworks/Apple80211.framework/Resources/airport -I

/System/Library/PrivateFrameworks/Apple80211.framework/Resources/airport -I  | awk -F' SSID: '  '/ SSID: / {print $2}'

