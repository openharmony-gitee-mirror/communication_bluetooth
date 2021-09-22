/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_BLUETOOTH_STANDARD_A2DP_SOURCE_SERVER_H
#define OHOS_BLUETOOTH_STANDARD_A2DP_SOURCE_SERVER_H

#include "bluetooth_a2dp_src_stub.h"
#include "raw_address.h"

namespace OHOS {
namespace Bluetooth {

class BluetoothA2dpSourceServer : public BluetoothA2dpSrcStub {
public:
    BluetoothA2dpSourceServer()
    {}
    ~BluetoothA2dpSourceServer()
    {}

    void Init();
    void Destroy();
    int GetDeviceState(const RawAddress &device) override;
    void RegisterObserver(const sptr<IBluetoothA2dpSrcObserver> &observer) override;
};
}  // namespace Bluetooth
}  // namespace OHOS
#endif  // OHOS_BLUETOOTH_STANDARD_A2DP_SOURCE_SERVER_H