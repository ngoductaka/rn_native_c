import {TurboModule, TurboModuleRegistry} from 'react-native';

export interface Spec extends TurboModule {
  readonly dndFun: (input: string) => string;
}

export default TurboModuleRegistry.getEnforcing<Spec>(
  'NativeDnd',
);