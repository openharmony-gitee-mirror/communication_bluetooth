/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "bluetooth_gatt_client.h"
#include "bluetooth_gatt_manager.h"
#include "uuid.h"
#include "vector"

using namespace testing;
using namespace testing::ext;
using namespace bluetooth;

namespace OHOS {
namespace Bluetooth {

// URI: scheme://authority/path1/path2/path3?id = 1&name = mingming&old#fragment
/*
 * @tc.number: Xxx_Unittest_AttachId_GetId_0100
 * @tc.name: AttachId/GetId
 * @tc.desc: Test if attachd and getid return values are correct.
 */

class GattClientCallbackTest : public GattClientCallback {
public:
    GattClientCallbackTest()
    {}
    ~GattClientCallbackTest()
    {}

    void OnConnectionStateChanged(int connectionState, int ret)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnConnectionStateChanged called";
    }

    void OnCharacteristicChanged(const GattCharacteristic &characteristic)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnCharacteristicChanged called";
    }

    void OnCharacteristicReadResult(const GattCharacteristic &characteristic, int ret)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnCharacteristicReadResult called";
    }

    void OnCharacteristicWriteResult(const GattCharacteristic &characteristic, int ret)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnCharacteristicWriteResult called";
    }

    void OnDescriptorReadResult(const GattDescriptor &descriptor, int ret)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnDescriptorReadResult called";
    }

    void OnDescriptorWriteResult(const GattDescriptor &descriptor, int ret)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnDescriptorWriteResult called";
    }

    void OnMtuUpdate(int mtu, int ret)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnMtuUpdate called";
    }

    void OnServicesDiscovered(int status)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnServicesDiscovered called";
    }

    void OnConnectionParameterChanged(int interval, int latency, int timeout, int status)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnConnectionParameterChanged called";
    }

    void OnSetNotifyCharacteristic(int status)
    {
        GTEST_LOG_(INFO) << "GattClientCallbackTest::OnSetNotifyCharacteristic called";
    }
};

class GattManagerTest : public testing::Test {
public:
    GattManagerTest()
    {}
    ~GattManagerTest()
    {}

    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void GattManagerTest::SetUpTestCase(void)
{}
void GattManagerTest::TearDownTestCase(void)
{}
void GattManagerTest::SetUp()
{}

void GattManagerTest::TearDown()
{}

HWTEST_F(GattManagerTest, GattManager_ModuleTest_GetDevicesByStates, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "GattManager::GattManager ends";
    BluetoothRemoteDevice device;
    GattClient client(device);
    GattClientCallbackTest callback_;
    bool isAutoConnect = true;
    int transport = 12;
    client.Connect(callback_, isAutoConnect, transport);

    std::array<int, GattManager::GATT_CONNECTION_STATE_NUM> states = {1, 2, 3};

    GattManager test;
    test.GetDevicesByStates(states);

    GTEST_LOG_(INFO) << "GattManager::GetDevicesByState ends";
}

HWTEST_F(GattManagerTest, GattManager_ModuleTest_GetConnectedDevices, TestSize.Level1)
{

    GTEST_LOG_(INFO) << "GattManager::GattManager ends";
    BluetoothRemoteDevice device;
    GattClient client(device);
    GattClientCallbackTest callback_;
    bool isAutoConnect = true;
    int transport = 12;
    client.Connect(callback_, isAutoConnect, transport);

    GattManager test;
    test.GetConnectedDevices();

    GTEST_LOG_(INFO) << "GattManager::GetConnectedDevices ends";
}
}  // namespace Bluetooth
}  // namespace OHOS