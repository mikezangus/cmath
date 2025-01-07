import React, { useEffect, useState, useRef } from "react";
import { StyleSheet, Text, View } from "react-native";
import { Camera, useCameraDevices } from "react-native-vision-camera";


const styles = StyleSheet.create({
    container: {
        flex: 1
    }
});

export default function CameraView()
{
    const [hasPermission, setHasPermission] = useState<boolean | null>(null);
    const devices = useCameraDevices();
    const device = devices.find((d) => d.position === "back");
    const camera = useRef<Camera | null>(null);

    useEffect(() => {
        (async () => {
            const status = await Camera.requestCameraPermission();
            setHasPermission(status === "granted");
        })();
    }, []);

    if (hasPermission === null) {
        return (
            <View>
                <Text>
                    Requesting permission...
                </Text>
            </View>
        );
    }
    if (hasPermission === false) {
        return (
            <View>
                <Text>
                    No access to camera
                </Text>
            </View>
        );
    }
    if (device == null) {
        return (
            <Text>
                Loading camera...
            </Text>
        );
    }
    return (
        <View style={styles.container}>
            <Camera
                ref={camera}
                style={StyleSheet.absoluteFill}
                device={device}
                isActive={true}
            />
        </View>
    );
}
